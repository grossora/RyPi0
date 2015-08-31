#ifndef ERTOOL_ERANA1PI0KINVAR_CXX
#define ERTOOL_ERANA1PI0KINVAR_CXX

#include "ERAna1Pi0KinVar.h"

namespace ertool {

  ERAna1Pi0KinVar::ERAna1Pi0KinVar(const std::string& name) : AnaBase(name)
  , _mc(nullptr)
  , _reco(nullptr)
  , _comp(nullptr)
  , _MASS(nullptr)
  , _MassResolution(nullptr)
  , _MomentumResolution(nullptr)
  , _VertexResolution3D(nullptr)
  , _VertexResolutionX(nullptr)
  , _VertexResolutionY(nullptr)
  , _VertexResolutionZ(nullptr)
  , _ProductionAngleResolution(nullptr)
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
}




/*
 if (_mc) { delete _mc; }
    _mc = new TTree("_mc","_MC");
    _mc->Branch("x",&_mcx,"_mcx/D");
    _mc->Branch("y",&_mcy,"_mcy/D");
    _mc->Branch("z",&_mcz,"_mcz/D");
    _mc->Branch("px",&_mcpx,"_mcpx/D");
    _mc->Branch("py",&_mcpy,"_mcpy/D");
    _mc->Branch("pz",&_mcpz,"_mcpz/D");
    _mc->Branch("ptot",&_mcptot,"_mcptot/D");
    _mc->Branch("E1E2",&_mcE1E2,"_mcE1E2/D");
    _mc->Branch("costheta",&_mccostheta,"_mccostheta/D");
    _mc->Branch("mass",&_mcmass,"_mcmass/D");
	
 if (_reco) { delete _reco; }
    _reco = new TTree("_r","_MC");
    _reco->Branch("x",&_rx,"_rx/D");
    _reco->Branch("y",&_ry,"_ry/D");
    _reco->Branch("z",&_rz,"_rz/D");
    _reco->Branch("px",&_rpx,"_rpx/D");
    _reco->Branch("py",&_rpy,"_rpy/D");
    _reco->Branch("pz",&_rpz,"_rpz/D");
    _reco->Branch("E1E2",&_rE1E2,"_rE1E2/D");
    _reco->Branch("costheta",&_rcostheta,"_rcostheta/D");
    _reco->Branch("mass",&_rmass,"_rmass/D");


 if (_comp) { delete _comp; }
    _comp = new TTree("_comp","_Comp");
//=======mcpart
    _comp->Branch("mcx",&_mcx,"_mcx/D");
    _comp->Branch("mcy",&_mcy,"_mcy/D");
    _comp->Branch("mcz",&_mcz,"_mcz/D");
    _comp->Branch("mcpx",&_mcpx,"_mcpx/D");
    _comp->Branch("mcpy",&_mcpy,"_mcpy/D");
    _comp->Branch("mcpz",&_mcpz,"_mcpz/D");
    _comp->Branch("mcptot",&_mcptot,"_mcptot/D");
    _comp->Branch("mcE1E2",&_mcE1E2,"_mcE1E2/D");
    _comp->Branch("mccostheta",&_mccostheta,"_mccostheta/D");
    _comp->Branch("mcmass",&_mcmass,"_mcmass/D");
    _comp->Branch("shE1",&_sh_energy_1_val,"_sh_energy_1_val/D");
    _comp->Branch("shE2",&_sh_energy_2_val,"_sh_energy_2_val/D");
    _comp->Branch("mcshPhi1",&_sh_phi_1_true,"_sh_phi_1_true/D");
    _comp->Branch("mcshPhi2",&_sh_phi_2_true,"_sh_phi_2_true/D");
    _comp->Branch("mcshPhi1",&_sh_theta_1_true,"_sh_theta_1_true/D");
    _comp->Branch("mcshPhi2",&_sh_theta_2_true,"_sh_theta_2_true/D");
//=======reco part
    _comp->Branch("rx",&_rx,"_rx/D");
    _comp->Branch("ry",&_ry,"_ry/D");
    _comp->Branch("rz",&_rz,"_rz/D");
    _comp->Branch("rpx",&_rpx,"_rpx/D");
    _comp->Branch("rpy",&_rpy,"_rpy/D");
    _comp->Branch("rpz",&_rpz,"_rpz/D");
    _comp->Branch("rptot",&_rptot,"_rptot/D");
    _comp->Branch("rmass",&_rmass,"_rmass/D");
    _comp->Branch("rE1E2",&_rE1E2,"_rE1E2/D");
    _comp->Branch("rcostheta",&_rcostheta,"_rcostheta/D");
    _comp->Branch("rmass",&_rmass,"_rmass/D");
    _comp->Branch("shE1r",&_sh_energy_1_valr,"_sh_energy_1_valr/D");
    _comp->Branch("shE2r",&_sh_energy_2_valr,"_sh_energy_2_valr/D");
    _comp->Branch("rshPhi1",&_sh_phi_1_reco,"_sh_phi_1_reco/D");
    _comp->Branch("rshPhi2",&_sh_phi_2_reco,"_sh_phi_2_reco/D");
    _comp->Branch("rshPhi1",&_sh_theta_1_reco,"_sh_theta_1_reco/D");
    _comp->Branch("rshPhi2",&_sh_theta_2_reco,"_sh_theta_2_reco/D");

//=======precomute things
    _comp->Branch("dr",&_dr,"_dr/D");
    _comp->Branch("dmom",&_dmom,"_dmom/D");
    _comp->Branch("dmass",&_dmass,"_dmass/D");
    _comp->Branch("dsh1",&_sh_angle_1,"_sh_angle_1/D");
    _comp->Branch("dsh2",&_sh_angle_2,"_sh_angle_2/D");
    _comp->Branch("dshE1",&_sh_energy_1,"_sh_energy_1/D");
    _comp->Branch("dshE2",&_sh_energy_2,"_sh_energy_2/D");
*/
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
	// Get the truth info. 
//	unsigned int mcpi0ID = -999;
//	unsigned int mcgammaAID = -999;
//	unsigned int mcgammaBID = -999;
//	bool MCAll = true;

//====================================================================================================================================
// Just do the pi0 info first
//====================================================================================================================================
	
	unsigned int mcpi0id =-999;	
	int  pi0counter = 0;
	 for( auto const & mcp : mcparticles){
			if(mcp.PdgCode()==111){mcpi0id = mcp.ID(); pi0counter++;}
	}// For loop over mc

	if(pi0counter==1){ 

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
				}// if reco counter ==1

		}// if pi0coiunter ==1
/*

//====================================================================================================================================
//=============MC Particle Info=======================================================================================================
//====================================================================================================================================

	bool pi0evt = false;
	 for( auto const & mcp : mcparticles){
			if(mcp.PdgCode()==111){mcpi0ID = mcp.ID(); pi0evt=true;}
	}// for look over mcparticles

	if(pi0evt) return true;
	auto pi0daughters = mcgraph.GetAllDescendantNodes(mcpi0ID);
	if(pi0daughters.size()!=2) return true;
	
	if( pi0daughters.size() ==2){
		mcgammaAID = pi0daughters[0];
		mcgammaBID = pi0daughters[1];
		}

	if(mcpi0ID>10000|| mcgammaAID>10000 || mcgammaBID>10000){ MCAll=false; return true;}// haha this is a really shitty hack R.G.
	_nGoodEvents++;
	
	auto mcpartpi0 = mcgraph.GetParticle(mcpi0ID);
	auto mcpartga = mcgraph.GetParticle(mcgammaAID);
	auto mcpartgb = mcgraph.GetParticle(mcgammaBID);
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================

	double mcpi0mass =  sqrt(2.0*mcpartga.Energy()*mcpartgb.Energy()*(1.0- mcpartga.Momentum().Dot(mcpartgb.Momentum())/(mcpartga.Momentum().Length()*mcpartgb.Momentum().Length())) );
	//==============
	//Fill out the mc tree info
	//==============
	_mcx = mcpartpi0.Vertex()[0];
	_mcy = mcpartpi0.Vertex()[1];
	_mcz = mcpartpi0.Vertex()[2];
	_mcpx = mcpartpi0.Momentum()[0];
	_mcpy = mcpartpi0.Momentum()[1];
	_mcpz = mcpartpi0.Momentum()[2];
	_mcptot = mcpartpi0.Momentum().Length();
	_mcE1E2 = mcpartga.Energy()*mcpartgb.Energy();
	_mccostheta = mcpartga.Momentum().Dot(mcpartgb.Momentum())/(mcpartga.Momentum().Length()*mcpartgb.Momentum().Length());
	_mcmass = mcpi0mass;

	if(MCAll) _mc->Fill();
	//==============

//====================================================================================================================================
//===========RECO Particle Info=======================================================================================================
//====================================================================================================================================
	unsigned int pi0ID = -999;
	unsigned int gammaAID = -999;
	unsigned int gammaBID = -999;
	bool Recopi0 = false;
	bool RecoAll = false;
        auto particles = graph.GetParticleArray();
	for(auto const & p : particles){if(p.PdgCode()==111){ pi0ID = p.ID(); Recopi0 = true;}}// Loop over reco graph

	if(!Recopi0) return true;
	auto recodaughters = graph.GetAllDescendantNodes(pi0ID);

	if(recodaughters.size()!=2){return true;}
	if(recodaughters.size()==2){ gammaAID = recodaughters[0]; gammaBID = recodaughters[1]; _nRecoEvents++; RecoAll=true;}
	
	auto partpi0 = graph.GetParticle(pi0ID);
	auto partga = graph.GetParticle(gammaAID);
	auto partgb = graph.GetParticle(gammaBID);

	double pi0mass =  sqrt(2.0*partga.Energy()*partgb.Energy()*(1.0- partga.Momentum().Dot(partgb.Momentum())/(partga.Momentum().Length()*partgb.Momentum().Length())) );

	//==============
	//Fill out the reco tree info
	//==============
	_rx = partpi0.Vertex()[0];
	_ry = partpi0.Vertex()[1];
	_rz = partpi0.Vertex()[2];
	_rpx = partpi0.Momentum()[0];
	_rpy = partpi0.Momentum()[1];
	_rpz = partpi0.Momentum()[2];
	_rptot = partpi0.Momentum().Length();
	_rE1E2 = partga.Energy()*partgb.Energy();
	_rcostheta = partga.Momentum().Dot(partgb.Momentum())/(partga.Momentum().Length()*partgb.Momentum().Length());
	_rmass = pi0mass;

	_reco->Fill();
	//==============
//====================================================================================================================================
//====================================================================================================================================
//====================================================================================================================================



//====================================================================================================================================
//===========Compare Shower info =====================================================================================================
//====================================================================================================================================
	// First compare the Vertex Resolution of the pi0 
	auto vertexdif = mcpartpi0.Vertex() - partpi0.Vertex();
	auto ProductionAngleDif = acos(_rpz/_rptot) - acos(_mcpz/_mcptot); 
	auto momentumdif = mcpartpi0.Momentum().Length() - partpi0.Momentum().Length();
	double massdif= mcpi0mass-pi0mass;

	// Match the Reco Photon to the Best Truth Photon 
		// Match based on start point
		// We can also imagine basing them on direction/charge/ect
	bool AABB = false;
	bool ABBA = false;
	auto mcganorm = mcpartga.Momentum()/mcpartga.Momentum().Length();
	auto mcgbnorm = mcpartgb.Momentum()/mcpartgb.Momentum().Length();
	auto ganorm = partga.Momentum()/partga.Momentum().Length();
	auto gbnorm = partgb.Momentum()/partgb.Momentum().Length();
	auto mcgaSP = mcpartga.Vertex();
	auto mcgbSP = mcpartgb.Vertex();
	auto gaSP = partga.Vertex();
	auto gbSP = partgb.Vertex();
		// Get the theta/phi values 
		auto mcgaphi = mcganorm.Phi();
		auto gaphi = ganorm.Phi();
		auto mcgatheta = mcganorm.Theta();
		auto gatheta = ganorm.Theta();
		auto mcgbphi = mcgbnorm.Phi();
		auto gbphi = gbnorm.Phi();
		auto mcgbtheta = mcgbnorm.Theta();
		auto gbtheta = gbnorm.Theta();


	auto mcadota = mcganorm.Dot(ganorm);
	auto mcadotb = mcganorm.Dot(gbnorm);
	auto mcbdota = mcgbnorm.Dot(ganorm);
	auto mcbdotb = mcgbnorm.Dot(gbnorm);
	auto mcaAnglea = acos(mcadota);
	auto mcaAngleb = acos(mcadotb);
	auto mcbAnglea = acos(mcbdota);
	auto mcbAngleb = acos(mcbdotb);
	
	auto mcaSPa = (mcgaSP - gaSP).Length();
	auto mcbSPb = (mcgbSP - gbSP).Length();
	auto mcaSPb = (mcgaSP - gbSP).Length();
	auto mcbSPa = (mcgbSP - gaSP).Length();

	if(mcadota+mcbdotb>mcadotb+mcbdota) AABB=true;
	if(mcadota+mcbdotb<mcadotb+mcbdota) ABBA=true;
	
	//compare photon direction
	if(AABB){
	_sh_angle_1 = mcaAnglea;
	_sh_angle_2 = mcbAngleb;
	_sh_phi_1_true = mcgaphi;
	_sh_phi_1_reco = gaphi;
	_sh_phi_2_true = mcgbphi;
	_sh_phi_2_reco = gbphi;
	_sh_theta_1_true = mcgatheta;
	_sh_theta_1_reco = gatheta;
	_sh_theta_2_true = mcgbtheta;
	_sh_theta_2_reco = gbtheta;
	_sh_energy_1 = mcpartga.Energy() -partga.Energy();
	_sh_energy_1_val = mcpartga.Energy();
	_sh_energy_1_valr = partga.Energy();
	_sh_energy_2 = mcpartgb.Energy() -partgb.Energy();
	_sh_energy_2_val = mcpartgb.Energy();
	_sh_energy_2_valr = partgb.Energy();
	}
	if(ABBA){
	_sh_angle_1 = mcaAnglea;
	_sh_angle_2 = mcbAngleb;
	_sh_phi_1_true = mcgaphi;
	_sh_phi_1_reco = gbphi;
	_sh_phi_2_true = mcgbphi;
	_sh_phi_2_reco = gaphi;
	_sh_theta_1_true = mcgatheta;
	_sh_theta_1_reco = gbtheta;
	_sh_theta_2_true = mcgbtheta;
	_sh_theta_2_reco = gatheta;
	_sh_energy_1 = mcpartga.Energy() -partgb.Energy();
	_sh_energy_1_val = mcpartga.Energy();
	_sh_energy_1_valr = partgb.Energy();
	_sh_energy_2 = mcpartgb.Energy() -partga.Energy();
	_sh_energy_2_val = mcpartgb.Energy();
	_sh_energy_2_valr = partga.Energy();
	}
	
	//==============
	//Fill out the compare tree info
	//==============
	_dr = vertexdif.Length();
	_dmom = momentumdif;
	_dmass = massdif;
	
	if(RecoAll && MCAll){
	 _comp->Fill();
	// _VertexResolution3D->Fill(_dr);
//	 _VertexResolutionX->Fill(vertexdif[0]);
//	 _VertexResolutionY->Fill(vertexdif[1]);
//	 _VertexResolutionZ->Fill(vertexdif[2]);
//	 _ProductionAngleResolution->Fill(ProductionAngleDif*180./3.14159265);
	}// if we have reconstructed this
	
	//==============

*/



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
