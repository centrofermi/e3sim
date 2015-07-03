// 2015-07-03 modified
// Fabrizio Coccetti [fabrizio.coccetti@centrofermi.it]
// run as root 'muonDistribution.C("1000",100000,9)'
//

#include "TCanvas.h"
#include "TH2.h"
#include "TF2.h"
#include "TMath.h"
#include "TROOT.h"
#include "TBranch.h"
#include "TTree.h"
#include "TFile.h"
#include "TStyle.h"


void muonDistribution(char *energyValue, int firstNumber, int nFiles)
{
    cout  << "Analyzing Energy " << energyValue << " GeV" << endl;
    gROOT->Reset();
    gROOT->SetStyle("Plain");
    gStyle->SetPalette(1);
    char titleHist[300];
    char fileNameHist[200];
    char fileName[150];
    char inputdir[100];
    //sprintf(inputdir, "data/%s/root/",energyValue);
    sprintf(inputdir, "./%s/",energyValue);
    cout << "Data dir:  " << inputdir << endl;
    const Int_t MAXSIZE = 950000; // maximum number of particles in a shower
    Int_t j;         // index for single particles
    int i;        // index for file names
    Double_t r;     // distance for Muon lateral distribution

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
   UInt_t *         particle__fUniqueID;   //[particle._]
   UInt_t *         particle__fBits;   //[particle._]
   Int_t *          particle__CorsikaID;   //[particle._]
   Int_t *          particle__ParticleID;   //[particle._]
   Int_t *          particle__ObservationLevel;   //[particle._]
   Int_t *          particle__HadronicGeneration;   //[particle._]
   Double_t *       particle__Px;   //[particle._]
   Double_t *       particle__Py;   //[particle._]
   Double_t *       particle__Pz;   //[particle._]
   Double_t *       particle__x;   //[particle._]
   Double_t *       particle__y;   //[particle._]
   Double_t *       particle__Time;   //[particle._]
   Double_t *       particle__Weight;   //[particle._]
   Int_t           long__;
   UInt_t *         long__fUniqueID;   //[long._]
   UInt_t *         long__fBits;   //[long._]
   Float_t *       long__Depth;   //[long._]
   ULong64_t *      long__nGammas;   //[long._]
   ULong64_t *      long__nElectrons;   //[long._]
   ULong64_t *      long__nPositrons;   //[long._]
   ULong64_t *      long__nMuons;   //[long._]
   ULong64_t *      long__nAntiMuons;   //[long._]
   ULong64_t *      long__nHadrons;   //[long._]
   ULong64_t *      long__nCharged;   //[long._]
   ULong64_t *      long__nNuclei;   //[long._]
   ULong64_t *      long__nCherenkov;   //[long._]
   Int_t           cherenkov__;
   UInt_t *         cherenkov__fUniqueID;   //[cherenkov._]
   UInt_t *         cherenkov__fBits;   //[cherenkov._]
   Float_t *        cherenkov__nPhotons;   //[cherenkov._]
   Float_t *        cherenkov__x;   //[cherenkov._]
   Float_t *        cherenkov__y;   //[cherenkov._]
   Float_t *        cherenkov__u;   //[cherenkov._]
   Float_t *        cherenkov__v;   //[cherenkov._]
   Float_t *        cherenkov__Time;   //[cherenkov._]
   Float_t *        cherenkov__ProductionHeight;   //[cherenkov._]
   Float_t *        cherenkov__Weight;   //[cherenkov._]


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

    //
    // DEFINE Histograms
    //
    TH1F *hEnergy = new TH1F("hEnergy", "Energy Distribution",100,0,1e8);
    TH1F *hTheta = new TH1F("hTheta", "Theta Distribution",100,0,4);
    TH1F *hPhi = new TH1F("hPhi", "Phi Distribution",100,-4,4);
    TH1F *hMuons = new TH1F("hMuons", "Muon Number Distribution",100,0,1000);
    TH1D *hr = new TH1D("hr", "Muon Lateral Distribution",160,0,16000);
    TH1D *hcrownarea = new TH1D("hcrownarea", "Area of the Circular Crown",160,0,16000);

    // BEGIN LOOP on files
    for(i=0; i<nFiles; i++)
    {
    // Generate filename
    sprintf(fileName,"%s/DAT%06d.root", inputdir, firstNumber+i);
    // Open filename
    TFile *myfile = new TFile(fileName,"READ");
    if (myfile->IsZombie())
        {
          cout << "Oh my God! The file:\t" << fileName
              << "\tdoes not exists" << endl;
          continue;
        }
    cout << "\r\n";
    cout << "Analyzing file: " << fileName;

/*    // Generate filename
    sprintf(filename.c_str(),"%s/DAT%06d.root",inputdir,i);
    // Open filename
    TFile *myfile = new TFile(filename.c_str(),"READ"); */
    TTree *sim = (TTree*)myfile->Get("sim");

    sim->SetMakeClass(1);

    particle__x = new Double_t[MAXSIZE];
    particle__y = new Double_t[MAXSIZE];
    particle__Px = new Double_t[MAXSIZE];
    particle__Py = new Double_t[MAXSIZE];
    particle__Pz = new Double_t[MAXSIZE];
    particle__Time = new Double_t[MAXSIZE];
    particle__ParticleID = new Int_t[MAXSIZE];

   sim->SetBranchAddress("shower.TObject.fUniqueID", &shower_TObject_fUniqueID, &b_shower_TObject_fUniqueID);
   sim->SetBranchAddress("shower.TObject.fBits", &shower_TObject_fBits, &b_shower_TObject_fBits);
   sim->SetBranchAddress("shower.EventID", &shower_EventID, &b_shower_EventID);
   sim->SetBranchAddress("shower.Energy", &shower_Energy, &b_shower_Energy);
   sim->SetBranchAddress("shower.StartingAltitude", &shower_StartingAltitude, &b_shower_StartingAltitude);
   sim->SetBranchAddress("shower.FirstTarget", &shower_FirstTarget, &b_shower_FirstTarget);
   sim->SetBranchAddress("shower.FirstHeight", &shower_FirstHeight, &b_shower_FirstHeight);
   sim->SetBranchAddress("shower.Theta", &shower_Theta, &b_shower_Theta);
   sim->SetBranchAddress("shower.Phi", &shower_Phi, &b_shower_Phi);
   sim->SetBranchAddress("shower.RandomSeed[10]", shower_RandomSeed, &b_shower_RandomSeed);
   sim->SetBranchAddress("shower.RandomOffset[10]", shower_RandomOffset, &b_shower_RandomOffset);
   sim->SetBranchAddress("shower.nPhotons", &shower_nPhotons, &b_shower_nPhotons);
   sim->SetBranchAddress("shower.nElectrons", &shower_nElectrons, &b_shower_nElectrons);
   sim->SetBranchAddress("shower.nHadrons", &shower_nHadrons, &b_shower_nHadrons);
   sim->SetBranchAddress("shower.nMuons", &shower_nMuons, &b_shower_nMuons);
   sim->SetBranchAddress("shower.nParticlesWritten", &shower_nParticlesWritten, &b_shower_nParticlesWritten);
   sim->SetBranchAddress("shower.nPhotonsWritten", &shower_nPhotonsWritten, &b_shower_nPhotonsWritten);
   sim->SetBranchAddress("shower.nElectronsWritten", &shower_nElectronsWritten, &b_shower_nElectronsWritten);
   sim->SetBranchAddress("shower.nHadronsWritten", &shower_nHadronsWritten, &b_shower_nHadronsWritten);
   sim->SetBranchAddress("shower.nMuonsWritten", &shower_nMuonsWritten, &b_shower_nMuonsWritten);
   sim->SetBranchAddress("shower.GH_Nmax", &shower_GH_Nmax, &b_shower_GH_Nmax);
   sim->SetBranchAddress("shower.GH_t0", &shower_GH_t0, &b_shower_GH_t0);
   sim->SetBranchAddress("shower.GH_tmax", &shower_GH_tmax, &b_shower_GH_tmax);
   sim->SetBranchAddress("shower.GH_a", &shower_GH_a, &b_shower_GH_a);
   sim->SetBranchAddress("shower.GH_b", &shower_GH_b, &b_shower_GH_b);
   sim->SetBranchAddress("shower.GH_c", &shower_GH_c, &b_shower_GH_c);
   sim->SetBranchAddress("shower.GH_Chi2", &shower_GH_Chi2, &b_shower_GH_Chi2);
   sim->SetBranchAddress("shower.nPreshower", &shower_nPreshower, &b_shower_nPreshower);
   sim->SetBranchAddress("shower.CPUtime", &shower_CPUtime, &b_shower_CPUtime);
   sim->SetBranchAddress("particle.", &particle__, &b_particle__);
   sim->SetBranchAddress("particle..fUniqueID", particle__fUniqueID, &b_particle__fUniqueID);
   sim->SetBranchAddress("particle..fBits", particle__fBits, &b_particle__fBits);
   sim->SetBranchAddress("particle..CorsikaID", particle__CorsikaID, &b_particle__CorsikaID);
   sim->SetBranchAddress("particle..ParticleID", particle__ParticleID, &b_particle__ParticleID);
   sim->SetBranchAddress("particle..ObservationLevel", particle__ObservationLevel, &b_particle__ObservationLevel);
   sim->SetBranchAddress("particle..HadronicGeneration", particle__HadronicGeneration, &b_particle__HadronicGeneration);
   sim->SetBranchAddress("particle..Px", particle__Px, &b_particle__Px);
   sim->SetBranchAddress("particle..Py", particle__Py, &b_particle__Py);
   sim->SetBranchAddress("particle..Pz", particle__Pz, &b_particle__Pz);
   sim->SetBranchAddress("particle..x", particle__x, &b_particle__x);
   sim->SetBranchAddress("particle..y", particle__y, &b_particle__y);
   sim->SetBranchAddress("particle..Time", particle__Time, &b_particle__Time);
   sim->SetBranchAddress("particle..Weight", particle__Weight, &b_particle__Weight);
   sim->SetBranchAddress("long.", &long__, &b_long__);
   sim->SetBranchAddress("long..fUniqueID", long__fUniqueID, &b_long__fUniqueID);
   sim->SetBranchAddress("long..fBits", long__fBits, &b_long__fBits);
   sim->SetBranchAddress("long..Depth", long__Depth, &b_long__Depth);
   sim->SetBranchAddress("long..nGammas", long__nGammas, &b_long__nGammas);
   sim->SetBranchAddress("long..nElectrons", long__nElectrons, &b_long__nElectrons);
   sim->SetBranchAddress("long..nPositrons", long__nPositrons, &b_long__nPositrons);
   sim->SetBranchAddress("long..nMuons", long__nMuons, &b_long__nMuons);
   sim->SetBranchAddress("long..nAntiMuons", long__nAntiMuons, &b_long__nAntiMuons);
   sim->SetBranchAddress("long..nHadrons", long__nHadrons, &b_long__nHadrons);
   sim->SetBranchAddress("long..nCharged", long__nCharged, &b_long__nCharged);
   sim->SetBranchAddress("long..nNuclei", long__nNuclei, &b_long__nNuclei);
   sim->SetBranchAddress("long..nCherenkov", long__nCherenkov, &b_long__nCherenkov);
   sim->SetBranchAddress("cherenkov.", &cherenkov__, &b_cherenkov__);
   sim->SetBranchAddress("cherenkov..fUniqueID", &cherenkov__fUniqueID, &b_cherenkov__fUniqueID);
   sim->SetBranchAddress("cherenkov..fBits", &cherenkov__fBits, &b_cherenkov__fBits);
   sim->SetBranchAddress("cherenkov..nPhotons", &cherenkov__nPhotons, &b_cherenkov__nPhotons);
   sim->SetBranchAddress("cherenkov..x", &cherenkov__x, &b_cherenkov__x);
   sim->SetBranchAddress("cherenkov..y", &cherenkov__y, &b_cherenkov__y);
   sim->SetBranchAddress("cherenkov..u", &cherenkov__u, &b_cherenkov__u);
   sim->SetBranchAddress("cherenkov..v", &cherenkov__v, &b_cherenkov__v);
   sim->SetBranchAddress("cherenkov..Time", &cherenkov__Time, &b_cherenkov__Time);
   sim->SetBranchAddress("cherenkov..ProductionHeight", &cherenkov__ProductionHeight, &b_cherenkov__ProductionHeight);
   sim->SetBranchAddress("cherenkov..Weight", &cherenkov__Weight, &b_cherenkov__Weight);


    // Below is always one
    //Int_t nentries = (Int_t)sim->GetEntries();
        //cout << "ENTRIES " << nentries;
    sim->GetEntry(0);
        cout << "shower.nMuons " << shower_nMuonsWritten << endl;
        cout << "shower.Theta " << shower_Theta << endl;
    //
    // FILL HISTOGRAMS
    //
    hEnergy->Fill(shower_Energy);
    hTheta->Fill(cos(shower_Theta));
    hPhi->Fill(shower_Phi);
    hMuons->Fill(shower_nMuonsWritten);
    j=0;
    while (j < shower_nParticlesWritten)
    {
      // check for muons
      if ((particle__ParticleID[j] == 5)
          || (particle__ParticleID[j] == 6))
        {
        r = sqrt(pow(particle__x[j],2)+pow(particle__y[j],2))/100;
        hr->Fill(r);
        }
      j++;
    }

    // Free Memory
    delete[] particle__x;
    delete[] particle__y;
    delete[] particle__Px;
    delete[] particle__Py;
    delete[] particle__Pz;
    delete[] particle__Time;
    delete[] particle__ParticleID;

    myfile->Close();
    } // END LOOP on Files

// TODO divide bins per circular crown area
// 1. compute histogram with circular crown areas
// 2. divide histrograms
    for (j=0;j<160;j++)
    {
    //hcrownarea->Fill(j*100,3.14159265359*(pow(((j+1)*100),2) - pow(j*100,2)));
    hcrownarea->SetBinContent(j+1,3.14159265359*(pow(((j+1)*100),2) - pow(j*100,2)));
    }
    hr->Divide(hcrownarea);
    hr->Scale(1./2.);
    // compute INTEGRAL
    //hr->Scale(1./nFiles);
    Double_t integral = hr->Integral(1,100);
    cout << endl;
    cout <<    "========" << endl;
    cout << "Energy (GeV): " << energyValue << endl;
    cout << "Showers: " << nFiles << endl;
    cout << "Integral: " << integral << endl;
    cout <<    "========" << endl;
    // write to logfile
    ofstream logfile;
    logfile.open ("summaryValues.txt",ios::app);
      if (logfile.is_open())
        {
         logfile << "Energy (GeV): " << energyValue << endl;
         logfile << "Showers: " << nFiles << endl;
         logfile << "Integral: " << integral << endl;
         logfile << "========" << endl;
         logfile.close();
         }

    // DRAW Histograms
    sprintf(titleHist, "Energy Distribution (Energy of the Primary: %s GeV)",energyValue);
    hEnergy->SetTitle(titleHist);
    hEnergy->GetXaxis()->SetTitle("GeV");
    //
    sprintf(titleHist, "Theta Distribution (Energy of the Primary: %s GeV)",energyValue);
    hTheta->SetTitle(titleHist);
    hTheta->GetXaxis()->SetTitle("Rad");
    //
    sprintf(titleHist, "Phi Distribution (Energy of the Primary: %s GeV)",energyValue);
    hPhi->SetTitle(titleHist);
    hPhi->GetXaxis()->SetTitle("Rad");
    //
    sprintf(titleHist, "Muon Number Distribution (Energy of the Primary: %s GeV)",energyValue);
    hMuons->SetTitle(titleHist);
    hMuons->GetXaxis()->SetTitle("#mu counts");
    //
    sprintf(titleHist, "Muon Lateral Distribution (Energy of the Primary: %s GeV)",energyValue);
    hr->SetTitle(titleHist);
    hr->GetXaxis()->SetTitle("r (m)");

  if (gROOT->IsBatch())
  {
//      sprintf(fileNameHist, "HIST_hEnergy_%s.C",energyValue);
//    hEnergy->SaveAs(fileNameHist);
//      sprintf(fileNameHist, "HIST_hTheta_%s.C",energyValue);
//    hTheta->SaveAs(fileNameHist);
//      sprintf(fileNameHist, "HIST_hPhi_%s.C",energyValue);
//    hPhi->SaveAs(fileNameHist);
//      sprintf(fileNameHist, "HIST_hMuonNumber_%s.C",energyValue);
//    hMuons->SaveAs(fileNameHist);
    TCanvas *c5 = new TCanvas("c5", "Muon Lateral Distribution",10,32,700,530);
    hr->Draw();
    TCanvas *c6 = new TCanvas("c6", "Crown Area Histogram",10,32,700,530);
    hcrownarea->Draw();
  }

//    TCanvas *c1 = new TCanvas("c1", "Energy",10,32,700,530);
//    hEnergy->Draw();
//    TCanvas *c2 = new TCanvas("c2", "Theta",10,32,700,530);
//    hTheta->Draw();
//    TCanvas *c3 = new TCanvas("c3", "Phi",10,32,700,530);
//    hPhi->Draw();
//    TCanvas *c4 = new TCanvas("c4", "Muon Number",10,32,700,530);
//    hMuons->Draw();

      sprintf(fileNameHist, "HIST_hMuonLateralDistrib_%s.C",energyValue);
    hr->SaveAs(fileNameHist);
      sprintf(fileNameHist, "HIST_hCrownAreaDistrib_%s.C",energyValue);
    hcrownarea->SaveAs(fileNameHist);
//  if (gROOT->IsBatch()) return;
}
