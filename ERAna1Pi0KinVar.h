/**
 * \file ERAna1Pi0KinVar.h
 *
 * \ingroup Pi0Ana
 * 
 * \brief Class def header for a class ERAna1Pi0KinVar
 *
 * @author ryan
 */

/** \addtogroup Pi0Ana

    @{*/

#ifndef ERTOOL_ERANA1PI0KINVAR_H
#define ERTOOL_ERANA1PI0KINVAR_H

#include "ERTool/Base/AnaBase.h"
#include "ERTool/Base/ParticleGraph.h"
#include "ERTool/Base/Particle.h"
#include "ERTool/Base/EventData.h"
#include <math.h>       /* cos */
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"




namespace ertool {

  /**
     \class ERAna1Pi0KinVar
     User custom Analysis class made by kazuhiro
   */
  class ERAna1Pi0KinVar : public AnaBase {
  
  public:

    /// Default constructor
    ERAna1Pi0KinVar(const std::string& name="ERAna1Pi0KinVar");

    /// Default destructor
    virtual ~ERAna1Pi0KinVar(){}

    /// Reset function
    virtual void Reset();

    /// Function to accept fclite::PSet
    void AcceptPSet(const ::fcllite::PSet& cfg);

    /// Called @ before processing the first event sample
    void ProcessBegin();

    /// Function to evaluate input showers and determine a score
    //bool Analyze(const EventData &data, const ParticleGraph &ps);
    bool Analyze(const EventData &data, const ParticleGraph &graph);

    /// Called after processing the last event sample
    void ProcessEnd(TFile* fout=nullptr);

    void SetReco(bool recon ){_recon = recon;}

	private: 
	
	bool _recon = true;

	//--Perm. Histos--
	TH1D* _MASS;
	TH1D* _MassResolution;
	TH1D* _MomentumResolution;
	TH1D* _VertexResolution3D;
	TH1D* _VertexResolutionX;
	TH1D* _VertexResolutionY;
	TH1D* _VertexResolutionZ;
	TH1D* _ProductionAngleResolution;
	
	//---------------
	TTree* _mc;
	double _mcx = -999;
	double _mcy = -999;
	double _mcz = -999;
	double _mcpx = -999;
	double _mcpy = -999;
	double _mcpz = -999;
	double _mcptot = -999;
	double _mcE1E2 = -999;
	double _mccostheta = -999;
	double _mcmass = -999;

	//---------------
		//======
	//---------------
	TTree* _reco;
	double _rx = -999;
	double _ry = -999;
	double _rz = -999;
	double _rpx = -999;
	double _rpy = -999;
	double _rpz = -999;
	double _rptot = -999;
	double _rE1E2 = -999;
	double _rcostheta = -999;
	double _rmass = -999;

	//---------------
		//======
	//---------------
	TTree* _comp;
	double _dr ;
	double _dmom ;
	double _dmass ;
	double _sh_angle_1 ;
	double _sh_angle_2 ;
	double _sh_energy_1 ;
	double _sh_energy_2 ;
	double _sh_energy_1_val ;
	double _sh_energy_2_val ;
	double _sh_energy_1_valr ;
	double _sh_energy_2_valr ;
	double _sh_phi_1_true ;
	double _sh_phi_2_true ;
	double _sh_phi_1_reco ;
	double _sh_phi_2_reco ;
	double _sh_theta_1_true ;
	double _sh_theta_2_true ;
	double _sh_theta_1_reco ;
	double _sh_theta_2_reco ;

     int _nEvents = 0;
     int _nGoodEvents = 0;
     int _nRecoEvents = 0;



  };
}
#endif

/** @} */ // end of doxygen group 
