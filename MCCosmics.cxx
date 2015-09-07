#ifndef LARLITE_MCCOSMICS_CXX
#define LARLITE_MCCOSMICS_CXX

#include "MCCosmics.h"

namespace larlite {

  bool MCCosmics::initialize() {
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

        for(auto const& p : mcpart){
	std::cout<<"Particle test cosmic cout"<<std::endl;
	if(p.PdgCode()==111) std::cout<<" Look at all these pi0! " <<p.PdgCode()<<std::endl;
	}



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

    return true;
  }

}
#endif
