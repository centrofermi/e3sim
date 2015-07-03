//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul  2 18:24:40 2015 by ROOT version 6.02/08
// from TTree sim/simulated showers
// found on file: DAT450000.root
//////////////////////////////////////////////////////////

#ifndef MyClass_h
#define MyClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TObject.h"
#include "TClonesArray.h"

class MyClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxshower = 1;
   const Int_t kMaxparticle_ = 1423381;
   const Int_t kMaxlong_ = 208;
   const Int_t kMaxcherenkov_ = 1;

   // Declaration of leaf types
 //crsIO::TShower  *shower_;
   UInt_t          shower_TObject_fUniqueID;
   UInt_t          shower_TObject_fBits;
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
   Int_t           particle__;
   UInt_t          particle__fUniqueID[kMaxparticle_];   //[particle._]
   UInt_t          particle__fBits[kMaxparticle_];   //[particle._]
   Int_t           particle__CorsikaID[kMaxparticle_];   //[particle._]
   Int_t           particle__ParticleID[kMaxparticle_];   //[particle._]
   Int_t           particle__ObservationLevel[kMaxparticle_];   //[particle._]
   Int_t           particle__HadronicGeneration[kMaxparticle_];   //[particle._]
   Double_t        particle__Px[kMaxparticle_];   //[particle._]
   Double_t        particle__Py[kMaxparticle_];   //[particle._]
   Double_t        particle__Pz[kMaxparticle_];   //[particle._]
   Double_t        particle__x[kMaxparticle_];   //[particle._]
   Double_t        particle__y[kMaxparticle_];   //[particle._]
   Double_t        particle__Time[kMaxparticle_];   //[particle._]
   Double_t        particle__Weight[kMaxparticle_];   //[particle._]
   Int_t           long__;
   UInt_t          long__fUniqueID[kMaxlong_];   //[long._]
   UInt_t          long__fBits[kMaxlong_];   //[long._]
   Float_t         long__Depth[kMaxlong_];   //[long._]
   ULong64_t       long__nGammas[kMaxlong_];   //[long._]
   ULong64_t       long__nElectrons[kMaxlong_];   //[long._]
   ULong64_t       long__nPositrons[kMaxlong_];   //[long._]
   ULong64_t       long__nMuons[kMaxlong_];   //[long._]
   ULong64_t       long__nAntiMuons[kMaxlong_];   //[long._]
   ULong64_t       long__nHadrons[kMaxlong_];   //[long._]
   ULong64_t       long__nCharged[kMaxlong_];   //[long._]
   ULong64_t       long__nNuclei[kMaxlong_];   //[long._]
   ULong64_t       long__nCherenkov[kMaxlong_];   //[long._]
   Int_t           cherenkov__;
   UInt_t          cherenkov__fUniqueID[kMaxcherenkov_];   //[cherenkov._]
   UInt_t          cherenkov__fBits[kMaxcherenkov_];   //[cherenkov._]
   Float_t         cherenkov__nPhotons[kMaxcherenkov_];   //[cherenkov._]
   Float_t         cherenkov__x[kMaxcherenkov_];   //[cherenkov._]
   Float_t         cherenkov__y[kMaxcherenkov_];   //[cherenkov._]
   Float_t         cherenkov__u[kMaxcherenkov_];   //[cherenkov._]
   Float_t         cherenkov__v[kMaxcherenkov_];   //[cherenkov._]
   Float_t         cherenkov__Time[kMaxcherenkov_];   //[cherenkov._]
   Float_t         cherenkov__ProductionHeight[kMaxcherenkov_];   //[cherenkov._]
   Float_t         cherenkov__Weight[kMaxcherenkov_];   //[cherenkov._]

   // List of branches
   TBranch        *b_shower_TObject_fUniqueID;   //!
   TBranch        *b_shower_TObject_fBits;   //!
   TBranch        *b_shower_EventID;   //!
   TBranch        *b_shower_Energy;   //!
   TBranch        *b_shower_StartingAltitude;   //!
   TBranch        *b_shower_FirstTarget;   //!
   TBranch        *b_shower_FirstHeight;   //!
   TBranch        *b_shower_Theta;   //!
   TBranch        *b_shower_Phi;   //!
   TBranch        *b_shower_RandomSeed;   //!
   TBranch        *b_shower_RandomOffset;   //!
   TBranch        *b_shower_nPhotons;   //!
   TBranch        *b_shower_nElectrons;   //!
   TBranch        *b_shower_nHadrons;   //!
   TBranch        *b_shower_nMuons;   //!
   TBranch        *b_shower_nParticlesWritten;   //!
   TBranch        *b_shower_nPhotonsWritten;   //!
   TBranch        *b_shower_nElectronsWritten;   //!
   TBranch        *b_shower_nHadronsWritten;   //!
   TBranch        *b_shower_nMuonsWritten;   //!
   TBranch        *b_shower_GH_Nmax;   //!
   TBranch        *b_shower_GH_t0;   //!
   TBranch        *b_shower_GH_tmax;   //!
   TBranch        *b_shower_GH_a;   //!
   TBranch        *b_shower_GH_b;   //!
   TBranch        *b_shower_GH_c;   //!
   TBranch        *b_shower_GH_Chi2;   //!
   TBranch        *b_shower_nPreshower;   //!
   TBranch        *b_shower_CPUtime;   //!
   TBranch        *b_particle__;   //!
   TBranch        *b_particle__fUniqueID;   //!
   TBranch        *b_particle__fBits;   //!
   TBranch        *b_particle__CorsikaID;   //!
   TBranch        *b_particle__ParticleID;   //!
   TBranch        *b_particle__ObservationLevel;   //!
   TBranch        *b_particle__HadronicGeneration;   //!
   TBranch        *b_particle__Px;   //!
   TBranch        *b_particle__Py;   //!
   TBranch        *b_particle__Pz;   //!
   TBranch        *b_particle__x;   //!
   TBranch        *b_particle__y;   //!
   TBranch        *b_particle__Time;   //!
   TBranch        *b_particle__Weight;   //!
   TBranch        *b_long__;   //!
   TBranch        *b_long__fUniqueID;   //!
   TBranch        *b_long__fBits;   //!
   TBranch        *b_long__Depth;   //!
   TBranch        *b_long__nGammas;   //!
   TBranch        *b_long__nElectrons;   //!
   TBranch        *b_long__nPositrons;   //!
   TBranch        *b_long__nMuons;   //!
   TBranch        *b_long__nAntiMuons;   //!
   TBranch        *b_long__nHadrons;   //!
   TBranch        *b_long__nCharged;   //!
   TBranch        *b_long__nNuclei;   //!
   TBranch        *b_long__nCherenkov;   //!
   TBranch        *b_cherenkov__;   //!
   TBranch        *b_cherenkov__fUniqueID;   //!
   TBranch        *b_cherenkov__fBits;   //!
   TBranch        *b_cherenkov__nPhotons;   //!
   TBranch        *b_cherenkov__x;   //!
   TBranch        *b_cherenkov__y;   //!
   TBranch        *b_cherenkov__u;   //!
   TBranch        *b_cherenkov__v;   //!
   TBranch        *b_cherenkov__Time;   //!
   TBranch        *b_cherenkov__ProductionHeight;   //!
   TBranch        *b_cherenkov__Weight;   //!

   MyClass(TTree *tree=0);
   virtual ~MyClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MyClass_cxx
MyClass::MyClass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DAT450000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("DAT450000.root");
      }
      f->GetObject("sim",tree);

   }
   Init(tree);
}

MyClass::~MyClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MyClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MyClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MyClass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("shower.TObject.fUniqueID", &shower_TObject_fUniqueID, &b_shower_TObject_fUniqueID);
   fChain->SetBranchAddress("shower.TObject.fBits", &shower_TObject_fBits, &b_shower_TObject_fBits);
   fChain->SetBranchAddress("shower.EventID", &shower_EventID, &b_shower_EventID);
   fChain->SetBranchAddress("shower.Energy", &shower_Energy, &b_shower_Energy);
   fChain->SetBranchAddress("shower.StartingAltitude", &shower_StartingAltitude, &b_shower_StartingAltitude);
   fChain->SetBranchAddress("shower.FirstTarget", &shower_FirstTarget, &b_shower_FirstTarget);
   fChain->SetBranchAddress("shower.FirstHeight", &shower_FirstHeight, &b_shower_FirstHeight);
   fChain->SetBranchAddress("shower.Theta", &shower_Theta, &b_shower_Theta);
   fChain->SetBranchAddress("shower.Phi", &shower_Phi, &b_shower_Phi);
   fChain->SetBranchAddress("shower.RandomSeed[10]", shower_RandomSeed, &b_shower_RandomSeed);
   fChain->SetBranchAddress("shower.RandomOffset[10]", shower_RandomOffset, &b_shower_RandomOffset);
   fChain->SetBranchAddress("shower.nPhotons", &shower_nPhotons, &b_shower_nPhotons);
   fChain->SetBranchAddress("shower.nElectrons", &shower_nElectrons, &b_shower_nElectrons);
   fChain->SetBranchAddress("shower.nHadrons", &shower_nHadrons, &b_shower_nHadrons);
   fChain->SetBranchAddress("shower.nMuons", &shower_nMuons, &b_shower_nMuons);
   fChain->SetBranchAddress("shower.nParticlesWritten", &shower_nParticlesWritten, &b_shower_nParticlesWritten);
   fChain->SetBranchAddress("shower.nPhotonsWritten", &shower_nPhotonsWritten, &b_shower_nPhotonsWritten);
   fChain->SetBranchAddress("shower.nElectronsWritten", &shower_nElectronsWritten, &b_shower_nElectronsWritten);
   fChain->SetBranchAddress("shower.nHadronsWritten", &shower_nHadronsWritten, &b_shower_nHadronsWritten);
   fChain->SetBranchAddress("shower.nMuonsWritten", &shower_nMuonsWritten, &b_shower_nMuonsWritten);
   fChain->SetBranchAddress("shower.GH_Nmax", &shower_GH_Nmax, &b_shower_GH_Nmax);
   fChain->SetBranchAddress("shower.GH_t0", &shower_GH_t0, &b_shower_GH_t0);
   fChain->SetBranchAddress("shower.GH_tmax", &shower_GH_tmax, &b_shower_GH_tmax);
   fChain->SetBranchAddress("shower.GH_a", &shower_GH_a, &b_shower_GH_a);
   fChain->SetBranchAddress("shower.GH_b", &shower_GH_b, &b_shower_GH_b);
   fChain->SetBranchAddress("shower.GH_c", &shower_GH_c, &b_shower_GH_c);
   fChain->SetBranchAddress("shower.GH_Chi2", &shower_GH_Chi2, &b_shower_GH_Chi2);
   fChain->SetBranchAddress("shower.nPreshower", &shower_nPreshower, &b_shower_nPreshower);
   fChain->SetBranchAddress("shower.CPUtime", &shower_CPUtime, &b_shower_CPUtime);
   fChain->SetBranchAddress("particle.", &particle__, &b_particle__);
   fChain->SetBranchAddress("particle..fUniqueID", particle__fUniqueID, &b_particle__fUniqueID);
   fChain->SetBranchAddress("particle..fBits", particle__fBits, &b_particle__fBits);
   fChain->SetBranchAddress("particle..CorsikaID", particle__CorsikaID, &b_particle__CorsikaID);
   fChain->SetBranchAddress("particle..ParticleID", particle__ParticleID, &b_particle__ParticleID);
   fChain->SetBranchAddress("particle..ObservationLevel", particle__ObservationLevel, &b_particle__ObservationLevel);
   fChain->SetBranchAddress("particle..HadronicGeneration", particle__HadronicGeneration, &b_particle__HadronicGeneration);
   fChain->SetBranchAddress("particle..Px", particle__Px, &b_particle__Px);
   fChain->SetBranchAddress("particle..Py", particle__Py, &b_particle__Py);
   fChain->SetBranchAddress("particle..Pz", particle__Pz, &b_particle__Pz);
   fChain->SetBranchAddress("particle..x", particle__x, &b_particle__x);
   fChain->SetBranchAddress("particle..y", particle__y, &b_particle__y);
   fChain->SetBranchAddress("particle..Time", particle__Time, &b_particle__Time);
   fChain->SetBranchAddress("particle..Weight", particle__Weight, &b_particle__Weight);
   fChain->SetBranchAddress("long.", &long__, &b_long__);
   fChain->SetBranchAddress("long..fUniqueID", long__fUniqueID, &b_long__fUniqueID);
   fChain->SetBranchAddress("long..fBits", long__fBits, &b_long__fBits);
   fChain->SetBranchAddress("long..Depth", long__Depth, &b_long__Depth);
   fChain->SetBranchAddress("long..nGammas", long__nGammas, &b_long__nGammas);
   fChain->SetBranchAddress("long..nElectrons", long__nElectrons, &b_long__nElectrons);
   fChain->SetBranchAddress("long..nPositrons", long__nPositrons, &b_long__nPositrons);
   fChain->SetBranchAddress("long..nMuons", long__nMuons, &b_long__nMuons);
   fChain->SetBranchAddress("long..nAntiMuons", long__nAntiMuons, &b_long__nAntiMuons);
   fChain->SetBranchAddress("long..nHadrons", long__nHadrons, &b_long__nHadrons);
   fChain->SetBranchAddress("long..nCharged", long__nCharged, &b_long__nCharged);
   fChain->SetBranchAddress("long..nNuclei", long__nNuclei, &b_long__nNuclei);
   fChain->SetBranchAddress("long..nCherenkov", long__nCherenkov, &b_long__nCherenkov);
   fChain->SetBranchAddress("cherenkov.", &cherenkov__, &b_cherenkov__);
   fChain->SetBranchAddress("cherenkov..fUniqueID", &cherenkov__fUniqueID, &b_cherenkov__fUniqueID);
   fChain->SetBranchAddress("cherenkov..fBits", &cherenkov__fBits, &b_cherenkov__fBits);
   fChain->SetBranchAddress("cherenkov..nPhotons", &cherenkov__nPhotons, &b_cherenkov__nPhotons);
   fChain->SetBranchAddress("cherenkov..x", &cherenkov__x, &b_cherenkov__x);
   fChain->SetBranchAddress("cherenkov..y", &cherenkov__y, &b_cherenkov__y);
   fChain->SetBranchAddress("cherenkov..u", &cherenkov__u, &b_cherenkov__u);
   fChain->SetBranchAddress("cherenkov..v", &cherenkov__v, &b_cherenkov__v);
   fChain->SetBranchAddress("cherenkov..Time", &cherenkov__Time, &b_cherenkov__Time);
   fChain->SetBranchAddress("cherenkov..ProductionHeight", &cherenkov__ProductionHeight, &b_cherenkov__ProductionHeight);
   fChain->SetBranchAddress("cherenkov..Weight", &cherenkov__Weight, &b_cherenkov__Weight);
   Notify();
}

Bool_t MyClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MyClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MyClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MyClass_cxx
