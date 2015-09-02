#ifndef ERTOOL_ERANA1PI0KINVAR_CXX
#define ERTOOL_ERANA1PI0KINVAR_CXX

#include "ERAna1Pi0KinVar.h"

namespace ertool {

  ERAna1Pi0KinVar::ERAna1Pi0KinVar(const std::string& name) : AnaBase(name)
//  , _mc(nullptr)
//  , _reco(nullptr)
//  , _comp(nullptr)
  , _MASS(nullptr)
  , _MassResolution(nullptr)
  , _MomentumResolution(nullptr)
  , _VertexResolution3D(nullptr)
  , _VertexResolutionX(nullptr)
  , _VertexResolutionY(nullptr)
  , _VertexResolutionZ(nullptr)
  , _ProductionAngleResolution(nullptr)
  , _Pi0EffvsMomentumMC(nullptr)
  , _Pi0EffvsMomentumRECO(nullptr)
  , _Pi0EffvsMomentum(nullptr)
  {
	
if(!_recon){
    delete _MASS;
    _MASS = new TH1D("MASS","#pi^{0} Mass ; Mass [MeV]; Events/MeV ",200,0,500);
    delete _MassResolution;
    _MassResolution = new TH1D("MassResolution","#pi^{0} Mass Resolution; Mass [MeV]; Events/MeV ",200,-100,100);
    delete _MomentumResolution;
    _MomentumResolution = new TH1D("MomentumResolution","#pi^{0} Momentum Resolution; Momentum [MeV]; Events/MeV ",200,-100,100);
    delete _VertexResolution3D;
    _VertexResolution3D = new TH1D("VertexResolution3D","3D Vertex Resolution of #pi^{0}; Vertex Displacement [cm]; Events/0.25cm ",100,0,25);
    delete _VertexResolutionX;
    _VertexResolutionX = new TH1D("VertexResolutionX","X VertexResolution;  Vertex Displacement [cm]; Events/0.25cm",200,-50,50);
    delete _VertexResolutionY;
    _VertexResolutionY = new TH1D("VertexResolutionY","Y VertexResolution;  Vertex Displacement [cm]; Events/0.25cm",200,-50,50);
    delete _VertexResolutionZ;
    _VertexResolutionZ = new TH1D("VertexResolutionZ","Z VertexResolution;  Vertex Displacement [cm]; Events/0.25cm",200,-50,50);
    delete _ProductionAngleResolution;
    _ProductionAngleResolution = new TH1D("ProductionAngleResolution"," #pi^{0} Production Angle Resolution; Degrees; Number of Events",200,-25,25);
	}
if(_recon){	
    delete _MASS;
    _MASS = new TH1D("MASS","#pi^{0} Mass ; Mass [MeV]; Events/MeV ",200,0,500);
    delete _MassResolution;
    _MassResolution = new TH1D("MassResolution","#pi^{0} Mass Resolution; Mass [MeV]; Events/MeV ",200,-200,200);
    delete _MomentumResolution;
    _MomentumResolution = new TH1D("MomentumResolution","#pi^{0} Momentum Resolution; Momentum [MeV]; Events/MeV ",200,-200,200);
    delete _VertexResolution3D;
    _VertexResolution3D = new TH1D("VertexResolution3D","3D Vertex Resolution of #pi^{0}; Vertex Displacement [cm]; Events/0.25cm ",200,0,160);
    delete _VertexResolutionX;
    _VertexResolutionX = new TH1D("VertexResolutionX","X VertexResolution;  Vertex Displacement [cm]; Events/0.25cm",400,-100,100);
    delete _VertexResolutionY;
    _VertexResolutionY = new TH1D("VertexResolutionY","Y VertexResolution;  Vertex Displacement [cm]; Events/0.25cm",400,-100,100);
    delete _VertexResolutionZ;
    _VertexResolutionZ = new TH1D("VertexResolutionZ","Z VertexResolution;  Vertex Displacement [cm]; Events/0.25cm",400,-100,100);
    delete _ProductionAngleResolution;
    _ProductionAngleResolution = new TH1D("ProductionAngleResolution"," #pi^{0} Production Angle Resolution; Degrees; Number of Events",300,-50,50);
    delete _Pi0EffvsMomentumMC;
    _Pi0EffvsMomentumMC = new TH1D("Pi0EffvsMomentumMC"," #pi^{0} Eff MC; Momentum[MeV]",10,0,1000);
    delete _Pi0EffvsMomentumRECO;
    _Pi0EffvsMomentumRECO = new TH1D("Pi0EffvsMomentumRECO"," #pi^{0} Eff RECO; Momentum[MeV]",10,0,1000);
    delete _Pi0EffvsMomentum;
    _Pi0EffvsMomentum = new TH1D("Pi0EffvsMomentum"," #pi^{0} Eff; Momentum[MeV]",10,0,1000);
}




	}

  void ERAna1Pi0KinVar::Reset()
  {}

  void ERAna1Pi0KinVar::AcceptPSet(const ::fcllite::PSet& cfg)
  {}

  void ERAna1Pi0KinVar::ProcessBegin()
  { 
     _nGoodEvents = 0;
     _nRecoEvents = 0;
     _nEvents = 0;

	}


  bool ERAna1Pi0KinVar::Analyze(const EventData &data, const ParticleGraph &graph)
  { 
	_nEvents++;
	// Set the Truth info 
        auto mcgraph = MCParticleGraph();
        auto mceventdata = MCEventData();
        auto mcparticles = mcgraph.GetParticleArray();

//====================================================================================================================================
// Just do the pi0 info first
//====================================================================================================================================
	
	unsigned int mcpi0id =-999;	
	int  pi0counter = 0;
	 for( auto const & mcp : mcparticles){
			if(mcp.PdgCode()==111){mcpi0id = mcp.ID(); pi0counter++;}
	}// For loop over mc

	if(pi0counter==1){ 

	// Log the info for mc
	
	_Pi0EffvsMomentumMC->Fill(mcgraph.GetParticle(mcpi0id).Momentum().Length());
		// look for reco pi0
		        auto particles = graph.GetParticleArray();
			int  recopi0counter = 0;
			unsigned int recopi0id = -999;
			for(auto const & p : particles){if(p.PdgCode()==111){ recopi0id = p.ID(); recopi0counter++;}}// Loop over reco graph
		
		
			if(recopi0counter==1){ 
			// we did it and have reco
			         auto mcpi0 = mcgraph.GetParticle(mcpi0id);
			         auto pi0 = graph.GetParticle(recopi0id);
				 auto dr = mcpi0.Vertex() - pi0.Vertex();
				auto pad = acos(pi0.Momentum()[2]/pi0.Momentum().Length())-acos(mcpi0.Momentum()[2]/mcpi0.Momentum().Length());
				 auto dmass = mcpi0.Mass() - pi0.Mass();
				auto massval = pi0.Mass();
				 auto dmomentum = mcpi0.Momentum().Length() - pi0.Momentum().Length();


				 _VertexResolution3D->Fill(dr.Length());
				 _VertexResolutionX->Fill(dr[0]);
				 _VertexResolutionY->Fill(dr[1]);
				 _VertexResolutionZ->Fill(dr[2]);
				 _ProductionAngleResolution->Fill(pad*180./3.14159265);	
				 _MASS->Fill(massval);	
				 _MassResolution->Fill(dmass);	
				 _MomentumResolution->Fill(dmomentum);	

	
				_Pi0EffvsMomentumRECO->Fill(mcpi0.Momentum().Length());
				}// if reco counter ==1

		}// if pi0coiunter ==1







	return true; }

  void ERAna1Pi0KinVar::ProcessEnd(TFile* fout)
  {
	//--Perm. Histos--
if(!_recon){
	_MASS->SetLineWidth(2);
	_MASS->SetLineColor(2);
	_MASS->Write();
	_MassResolution->SetLineWidth(2);
	_MassResolution->SetLineColor(2);
	_MassResolution->Write();
	_MomentumResolution->SetLineWidth(2);
	_MomentumResolution->SetLineColor(2);
	_MomentumResolution->Write();
	_VertexResolution3D->SetLineWidth(2);
	_VertexResolution3D->SetLineColor(2);
	_VertexResolution3D->Write();
	_VertexResolutionX->SetLineWidth(2);
	_VertexResolutionX->SetLineColor(2);
	_VertexResolutionX->Write();
	_VertexResolutionY->SetLineWidth(2);
	_VertexResolutionY->SetLineColor(2);
	_VertexResolutionY->Write();
	_VertexResolutionZ->SetLineWidth(2);
	_VertexResolutionZ->SetLineColor(2);
	_VertexResolutionZ->Write();
	 _ProductionAngleResolution->SetLineWidth(2);
	 _ProductionAngleResolution->SetLineColor(2);
	 _ProductionAngleResolution->Write();
}
	
if(_recon){
	_MASS->SetLineWidth(2);
	_MASS->SetLineColor(4);
	_MASS->Write();
	_MassResolution->SetLineWidth(2);
	_MassResolution->SetLineColor(4);
	_MassResolution->Write();
	_MomentumResolution->SetLineWidth(2);
	_MomentumResolution->SetLineColor(4);
	_MomentumResolution->Write();
	_VertexResolution3D->SetLineWidth(2);
	_VertexResolution3D->SetLineColor(4);
	_VertexResolution3D->Write();
	_VertexResolutionX->SetLineWidth(2);
	_VertexResolutionX->SetLineColor(4);
	_VertexResolutionX->Write();
	_VertexResolutionY->SetLineWidth(2);
	_VertexResolutionY->SetLineColor(4);
	_VertexResolutionY->Write();
	_VertexResolutionZ->SetLineWidth(2);
	_VertexResolutionZ->SetLineColor(4);
	_VertexResolutionZ->Write();
	 _ProductionAngleResolution->SetLineWidth(2);
	 _ProductionAngleResolution->SetLineColor(4);
	 _ProductionAngleResolution->Write();


	_Pi0EffvsMomentumMC->Write();
	_Pi0EffvsMomentumRECO->Write();
	_Pi0EffvsMomentum->Clone("Pi0EffvsMomentumRECO");
	_Pi0EffvsMomentum->Divide(_Pi0EffvsMomentumMC);
	_Pi0EffvsMomentum->Write();
	
}


/*
	_mc->Write();
	_reco->Write();
	_comp->Write();
	
	std::cout<<"Total Events in the file "<< _nEvents<<std::endl;
	std::cout<<"Total Good Events "<< _nGoodEvents<<std::endl;
	std::cout<<"Reco Efficiency"<< (double)_nRecoEvents/_nGoodEvents<<std::endl;
*/
	}

}

#endif
