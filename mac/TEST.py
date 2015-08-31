import sys, os
from ROOT import larlite as fmwk
from seltool import ertool


if len(sys.argv) < 2:
    msg  = '\n'
    msg += "Usage 1: %s $INPUT_ROOT_FILE\n" % sys.argv[0]
    msg += '\n'
    sys.stderr.write(msg)
    sys.exit(1)

# Create algorithm

my_algo = ertool.AlgoPi0()
my_algo.setVerbose(False)
my_algo.setMinShrEnergy(20)
my_algo.setMaxShrEnergy(1000)
my_algo.setIPMax(10)
my_algo.setMinFitMass(50)
my_algo.setMaxFitMass(200)
my_algo.setAngleMax(3.14)


my_algo2 = ertool.ERAlgoTrackPid()

my_algo3 = ertool.AlgoPrimaryFinder()
my_algo3.setVtxToTrkStartDist(1)
my_algo3.setVtxToTrkDist(1)
my_algo3.setVtxToShrStartDist(1)
my_algo3.setMaxIP(5)

my_algo4 = ertool.ERAlgoPrimaryPi0()
my_algo4.SetMinDistVtx(50)
my_algo4.SetMinDistEnd(50)
my_algo4.SetVerbose(True)

# Create MC filter
my_anaunit = fmwk.Pi0Reco()#ExampleERSelection()
my_proc = fmwk.ana_processor()
my_proc.enable_filter(True)
my_proc.enable_event_alignment(False)


# Set up ana for 1pi0 selection
my_ana = ertool.ERAnaPi0All()
my_ana.SetVerbose(False)

# Set up ana for resolution
#my_ana_res = ertool.ERAnaPi0GunEff()
my_ana_res = ertool. ERAnarecotopo()

# First lets make a filter that looks for a certain events
pi0_topo = fmwk.effpi0();
# 0 == inclusive 1 == 1pi0&&nopi+/-
pi0_topo.SetTopology(1);
# 0 == ntsignal 1 == signal
pi0_topo.SignalTopology(1);
# 0 == CC 1 == NC 
pi0_topo.SetCCNC(1);
pi0_topo.SetFVCut(17) #17);
pi0_topo.SetEnergyCut(20) #20);
pi0_topo.SetContainment(0) #0.05);



pi0_topoMC = fmwk.MCTopo();
pi0_topoMC.SetCCNC(1)
pi0_topoMC.SetTopology(1)
pi0_topoMC.SetFiducial(17)



#my_anaunit._mgr.AddAna(my_ana)
#my_anaunit._mgr.AddAlgo(my_algo)
my_anaunit._mgr.AddAna(my_ana_res)
#my_anaunit._mgr.AddAlgo(my_algo2)
#my_anaunit._mgr.AddAlgo(my_algo3)
#my_anaunit._mgr.AddAlgo(my_algo4)
my_anaunit._mgr._training_mode =False


# Set input root file
for x in xrange(len(sys.argv)-1):
    my_proc.add_input_file(sys.argv[x+1])

# Specify IO mode
#my_proc.set_io_mode(fmwk.storage_manager.kREAD)
my_proc.set_io_mode(fmwk.storage_manager.kBOTH)

# Specify output root file name
my_proc.set_ana_output_file("testana.root")

my_proc.set_output_file("testout.root")


# here set E-cut for Helper & Ana modules
my_anaunit._mgr._mc_for_ana = True

# ***************  Set Producers  ****************
# First Argument: True = MC, False = Reco
#my_anaunit.SetShowerProducer(True,"mcreco");
#my_anaunit.SetShowerProducer(False,"newdefaultreco");
#my_anaunit.SetShowerProducer(False,"pandoraNuShower");
#my_anaunit.SetShowerProducer(False,"mergeall");
#my_anaunit.SetTrackProducer(True,"mcreco");
#my_anaunit.SetTrackProducer(False,"stitchkalmanhit");
#my_anaunit.SetVtxProducer(True,"generator");
#my_anaunit.SetShowerProducer(False,"showerrecofuzzy");
my_anaunit.SetShowerProducer(False,"showerreco");
#my_anaunit.SetShowerProducer(True,"mcreco");
my_anaunit.SetTrackProducer(True,"mcreco");
#my_anaunit.SetVtxProducer(True,"generator");
#my_anaunit.SetShowerProducer(False,"showerrecofuzzy");
#my_anaunit.SetTrackProducer(False,"");
#my_anaunit.SetVtxProducer(False,"");
# ************************************************

my_proc.add_process(pi0_topoMC)
my_proc.add_process(pi0_topo)
#my_proc.add_process(my_anaunit)



my_proc.run()


# done!
print
print "Finished running ana_processor event loop!"
print

#my_algo.StoreParams()
sys.exit(0)

