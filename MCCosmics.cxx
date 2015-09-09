#ifndef LARLITE_MCCOSMICS_CXX
#define LARLITE_MCCOSMICS_CXX

#include "MCCosmics.h"

namespace larlite {

  bool MCCosmics::initialize()
 {

        _total_0pi0_events = 0 ;
        _total_1pi0_events = 0 ;
        _total_npi0_events = 0 ;
        _total_events = 0;

        FullTree = new TTree("FullTree","FullTree");
	FullTree->Branch("cospi0x",&cospi0x,"cospi0x/D");



    return true;
  }
  
  bool MCCosmics::analyze(storage_manager* storage) {
	
        // Bring in the info for the event
        auto mctruth = storage->get_data<event_mctruth>("generator");
            if(!mctruth) {
                print(larlite::msg::kERROR,__FUNCTION__,Form("Did not find specified data product, mctruth!"));
                return false;}// if no mctruth
	// Get all the particles
	// Get the Neutrino
        auto mcpart = mctruth->at(0).GetParticles();
        auto mcnu = mctruth->at(0).GetNeutrino();
        auto ev_mcshower = storage->get_data<event_mcshower>("mcreco");// Get the mcshower info

	std::vector<int> motherpi0ID;
	motherpi0ID.clear();
	std::cout<<" PRE Mother size vect"<<motherpi0ID.size()<<std::endl;
	for(auto const& mcs: *ev_mcshower){
	if(mcs.MotherPdgCode()==111){ std::cout<<" Look at all these pi0! from MCS " <<std::endl;
		std::cout<< " Track ID " <<mcs.MotherTrackID()<<std::endl;
		std::cout<< " Mother Process " <<mcs.MotherProcess()<<std::endl;
		std::cout<< " Ancestor Process " <<mcs.AncestorProcess()<<std::endl;
		std::cout<< " Ancestor PDG " <<mcs.AncestorPdgCode()<<std::endl;
		std::cout<< " pi0 x pos" <<mcs.MotherEnd().Position().X()<<std::endl;
		cospi0x = mcs.MotherEnd().Position().X();
		FullTree->Fill();
		motherpi0ID.push_back(mcs.MotherTrackID());
		}
		}
	std::sort(motherpi0ID.begin(),motherpi0ID.end());
	motherpi0ID.erase( unique ( motherpi0ID.begin(),motherpi0ID.end()),motherpi0ID.end());

	std::cout<<" Mother size vect"<<motherpi0ID.size()<<std::endl;
	
	//count up things 
	_total_events++;
	if(motherpi0ID.size()==0) _total_0pi0_events++;
	if(motherpi0ID.size()==1) _total_1pi0_events++;
	if(motherpi0ID.size()>1) _total_npi0_events++;



	

/*
//
	//=&==&==&==&==&==&
	// if ccnc or both 
	//=&==&==&==&==&==&
	if(!_bothccnc) if(_ccnc != mcnu.CCNC()) return false;

	//=&==&==&==&==&==&
	// What Type of Event 
	//=&==&==&==&==&==&
        int pi0    = 0;
        int cmeson      = 0;
	
        for(auto const& p : mcpart){
            auto x = p.Trajectory().at(0).X() ;
            auto y = p.Trajectory().at(0).Y() ;
            auto z = p.Trajectory().at(0).Z() ;
		// If the particle is contained then log 
		if(x<256.35-_fid && x>0+_fid && y<116.5-_fid && y>-116.5+_fid && z<1036.8-_fid && z>-0+_fid){ 
			if(p.PdgCode()==111 && p.StatusCode()==1) pi0++;
			if(abs(p.PdgCode()==211) && p.StatusCode()==1) cmeson++;
		}// If inside of the fiducial
	}// for loop over mcpart

if(_sig){
	// Now we see if we have a certain signal
	if(_topo==0) if(pi0==0) return false;// needs to see if this really matters
	if(_topo==1) if(pi0!=1) return false; 
	if(_topo==2) if(pi0!=1 && cmeson!=0) return false; 
	
	//=&==&==&==&==&==&==&==&==&==&==&
	// If we make it this far
	// Look at the daughter products 
	//=&==&==&==&==&==&==&==&==&==&==&
	// First we need to check if it is a dalitz decay
        for (auto const& sd : *ev_mcshower) if(sd.MotherPdgCode() == 111 && abs(sd.PdgCode()) == 11) return false;
	
	event_mcshower showers;
        for (auto const& s : *ev_mcshower){
	    if(pi0!=1) break;
            if(s.Start().E() > _showerenergy && s.DetProfile().E()>_showerdetenergy && s.Start().E()/s.DetProfile().E()>_showercontain) showers.push_back(s);
	}// for loop over the MC showers

	// so the idea is if we pass both showers then we should have a size 2
	// if we have else that means that means one of the showers was no good  
	if(showers.size()!=2) return false;
	// I believe we have reached the end.
	// atleast for the signal portion
}// if signal


	// THis is not robust.
	if(!_sig){ 	
		if(_topo==0) if(pi0==0) return true;// needs to see if this really matters
		if(_topo==1) if(pi0!=1) return true; 
		if(_topo==2) if(pi0!=1 && cmeson!=0) return true; 
		}
 //
*/ 
    return true;
  }

  bool MCCosmics::finalize() {

	std::cout<<"SUMMARY OF COSMIC PI0"<<std::endl;
	std::cout<<" 0 pi0 "<<_total_0pi0_events<< " Percent "<<(double)_total_0pi0_events/_total_events<<std::endl;
	std::cout<<" 1 pi0 "<<_total_1pi0_events<<" Percent "<<(double)_total_1pi0_events/_total_events<<std::endl;
	std::cout<<" n pi0 "<<_total_npi0_events<<" Percent "<<(double)_total_npi0_events/_total_events<<std::endl;
	std::cout<<" total evt"<<_total_events<<std::endl;

     if(_fout){
	FullTree->Write();
	}

    return true;
  }

}
#endif
