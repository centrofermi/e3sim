{
//////////////////////////////////////////////////////////
//   This file has been automatically generated 
//     (Thu Jul  2 18:25:47 2015 by ROOT version6.02/08)
//   from TTree sim/simulated showers
//   found on file: DAT450000.root
//////////////////////////////////////////////////////////


//Reset ROOT and connect tree file
   gROOT->Reset();
   TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DAT450000.root");
   if (!f) {
      f = new TFile("DAT450000.root");
   }
    f->GetObject("sim",tree);

//Declaration of leaves types
   UInt_t          shower_TObject_fUniqueID;
   UInt_t          shower_TObject_fBits;
   TTree*          shower_fParticles;
   TTree*          shower_fCherenkov;
   Int_t           shower_EventID;
   Float_t         shower_Energy;
   Float_t         shower_StartingAltitude;
   Int_t           shower_FirstTarget;
   Float_t         shower_FirstHeight;
   Float_t         shower_Theta;
   Float_t         shower_Phi;
   Int_t           shower_RandomSeed[10];
   Int_t           shower_RandomOffset[10];
   Float_t         shower_nPhotons;
   Float_t         shower_nElectrons;
   Float_t         shower_nHadrons;
   Float_t         shower_nMuons;
   Int_t           shower_nParticlesWritten;
   Int_t           shower_nPhotonsWritten;
   Int_t           shower_nElectronsWritten;
   Int_t           shower_nHadronsWritten;
   Int_t           shower_nMuonsWritten;
   Float_t         shower_GH_Nmax;
   Float_t         shower_GH_t0;
   Float_t         shower_GH_tmax;
   Float_t         shower_GH_a;
   Float_t         shower_GH_b;
   Float_t         shower_GH_c;
   Float_t         shower_GH_Chi2;
   Int_t           shower_nPreshower;
   Int_t           shower_CPUtime;
   UInt_t          particle__fUniqueID[1423381];
   UInt_t          particle__fBits[1423381];
   Int_t           particle__CorsikaID[1423381];
   Int_t           particle__ParticleID[1423381];
   Int_t           particle__ObservationLevel[1423381];
   Int_t           particle__HadronicGeneration[1423381];
   Double_t        particle__Px[1423381];
   Double_t        particle__Py[1423381];
   Double_t        particle__Pz[1423381];
   Double_t        particle__x[1423381];
   Double_t        particle__y[1423381];
   Double_t        particle__Time[1423381];
   Double_t        particle__Weight[1423381];
   UInt_t          long__fUniqueID[208];
   UInt_t          long__fBits[208];
   Float_t         long__Depth[208];
   ULong64_t       long__nGammas[208];
   ULong64_t       long__nElectrons[208];
   ULong64_t       long__nPositrons[208];
   ULong64_t       long__nMuons[208];
   ULong64_t       long__nAntiMuons[208];
   ULong64_t       long__nHadrons[208];
   ULong64_t       long__nCharged[208];
   ULong64_t       long__nNuclei[208];
   ULong64_t       long__nCherenkov[208];
   UInt_t          cherenkov__fUniqueID[0];
   UInt_t          cherenkov__fBits[0];
   Float_t         cherenkov__nPhotons[0];
   Float_t         cherenkov__x[0];
   Float_t         cherenkov__y[0];
   Float_t         cherenkov__u[0];
   Float_t         cherenkov__v[0];
   Float_t         cherenkov__Time[0];
   Float_t         cherenkov__ProductionHeight[0];
   Float_t         cherenkov__Weight[0];

   // Set branch addresses.
   sim->SetBranchAddress("shower.",&shower_);
   sim->SetBranchAddress("shower.TObject.fUniqueID",&shower_TObject_fUniqueID);
   sim->SetBranchAddress("shower.TObject.fBits",&shower_TObject_fBits);
   sim->SetBranchAddress("shower.fParticles",&shower_fParticles);
   sim->SetBranchAddress("shower.fCherenkov",&shower_fCherenkov);
   sim->SetBranchAddress("shower.EventID",&shower_EventID);
   sim->SetBranchAddress("shower.Energy",&shower_Energy);
   sim->SetBranchAddress("shower.StartingAltitude",&shower_StartingAltitude);
   sim->SetBranchAddress("shower.FirstTarget",&shower_FirstTarget);
   sim->SetBranchAddress("shower.FirstHeight",&shower_FirstHeight);
   sim->SetBranchAddress("shower.Theta",&shower_Theta);
   sim->SetBranchAddress("shower.Phi",&shower_Phi);
   sim->SetBranchAddress("shower.RandomSeed[10]",shower_RandomSeed);
   sim->SetBranchAddress("shower.RandomOffset[10]",shower_RandomOffset);
   sim->SetBranchAddress("shower.nPhotons",&shower_nPhotons);
   sim->SetBranchAddress("shower.nElectrons",&shower_nElectrons);
   sim->SetBranchAddress("shower.nHadrons",&shower_nHadrons);
   sim->SetBranchAddress("shower.nMuons",&shower_nMuons);
   sim->SetBranchAddress("shower.nParticlesWritten",&shower_nParticlesWritten);
   sim->SetBranchAddress("shower.nPhotonsWritten",&shower_nPhotonsWritten);
   sim->SetBranchAddress("shower.nElectronsWritten",&shower_nElectronsWritten);
   sim->SetBranchAddress("shower.nHadronsWritten",&shower_nHadronsWritten);
   sim->SetBranchAddress("shower.nMuonsWritten",&shower_nMuonsWritten);
   sim->SetBranchAddress("shower.GH_Nmax",&shower_GH_Nmax);
   sim->SetBranchAddress("shower.GH_t0",&shower_GH_t0);
   sim->SetBranchAddress("shower.GH_tmax",&shower_GH_tmax);
   sim->SetBranchAddress("shower.GH_a",&shower_GH_a);
   sim->SetBranchAddress("shower.GH_b",&shower_GH_b);
   sim->SetBranchAddress("shower.GH_c",&shower_GH_c);
   sim->SetBranchAddress("shower.GH_Chi2",&shower_GH_Chi2);
   sim->SetBranchAddress("shower.nPreshower",&shower_nPreshower);
   sim->SetBranchAddress("shower.CPUtime",&shower_CPUtime);
   sim->SetBranchAddress("particle.",particle__);
   sim->SetBranchAddress("particle..fUniqueID",particle__fUniqueID);
   sim->SetBranchAddress("particle..fBits",particle__fBits);
   sim->SetBranchAddress("particle..CorsikaID",particle__CorsikaID);
   sim->SetBranchAddress("particle..ParticleID",particle__ParticleID);
   sim->SetBranchAddress("particle..ObservationLevel",particle__ObservationLevel);
   sim->SetBranchAddress("particle..HadronicGeneration",particle__HadronicGeneration);
   sim->SetBranchAddress("particle..Px",particle__Px);
   sim->SetBranchAddress("particle..Py",particle__Py);
   sim->SetBranchAddress("particle..Pz",particle__Pz);
   sim->SetBranchAddress("particle..x",particle__x);
   sim->SetBranchAddress("particle..y",particle__y);
   sim->SetBranchAddress("particle..Time",particle__Time);
   sim->SetBranchAddress("particle..Weight",particle__Weight);
   sim->SetBranchAddress("long.",&long__);
   sim->SetBranchAddress("long..fUniqueID",long__fUniqueID);
   sim->SetBranchAddress("long..fBits",long__fBits);
   sim->SetBranchAddress("long..Depth",long__Depth);
   sim->SetBranchAddress("long..nGammas",long__nGammas);
   sim->SetBranchAddress("long..nElectrons",long__nElectrons);
   sim->SetBranchAddress("long..nPositrons",long__nPositrons);
   sim->SetBranchAddress("long..nMuons",long__nMuons);
   sim->SetBranchAddress("long..nAntiMuons",long__nAntiMuons);
   sim->SetBranchAddress("long..nHadrons",long__nHadrons);
   sim->SetBranchAddress("long..nCharged",long__nCharged);
   sim->SetBranchAddress("long..nNuclei",long__nNuclei);
   sim->SetBranchAddress("long..nCherenkov",long__nCherenkov);
   sim->SetBranchAddress("cherenkov.",&cherenkov__);
   sim->SetBranchAddress("cherenkov..fUniqueID",&cherenkov__fUniqueID);
   sim->SetBranchAddress("cherenkov..fBits",&cherenkov__fBits);
   sim->SetBranchAddress("cherenkov..nPhotons",&cherenkov__nPhotons);
   sim->SetBranchAddress("cherenkov..x",&cherenkov__x);
   sim->SetBranchAddress("cherenkov..y",&cherenkov__y);
   sim->SetBranchAddress("cherenkov..u",&cherenkov__u);
   sim->SetBranchAddress("cherenkov..v",&cherenkov__v);
   sim->SetBranchAddress("cherenkov..Time",&cherenkov__Time);
   sim->SetBranchAddress("cherenkov..ProductionHeight",&cherenkov__ProductionHeight);
   sim->SetBranchAddress("cherenkov..Weight",&cherenkov__Weight);

//     This is the loop skeleton
//       To read only selected branches, Insert statements like:
// sim->SetBranchStatus("*",0);  // disable all branches
// TTreePlayer->SetBranchStatus("branchname",1);  // activate branchname

   Long64_t nentries = sim->GetEntries();

   Long64_t nbytes = 0;
//   for (Long64_t i=0; i<nentries;i++) {
//      nbytes += sim->GetEntry(i);
//   }
}
