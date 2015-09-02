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
	
	TH1D* _Pi0EffvsMomentumMC;
	TH1D* _Pi0EffvsMomentumRECO;
	TH1D* _Pi0EffvsMomentum;
	//---------------
     int _nEvents = 0;
     int _nGoodEvents = 0;
     int _nRecoEvents = 0;



  };
}
#endif

/** @} */ // end of doxygen group 
