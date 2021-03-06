gROOT->SetStyle("Plain");
gStyle->SetFillColor(10);
.x HIST_hMuonLateralDistrib_1e8.C;
.x HIST_hMuonLateralDistrib_1e7.C;
TLegend *legend=new TLegend(0.6,0.65,0.88,0.85);
legend->AddEntry(h8,"Energy of primary proton: 10^{17} eV");
legend->AddEntry(h7,"Energy of primary proton: 10^{16} eV");
legend->AddEntry(h6,"Energy of primary proton: 10^{15} eV");
legend->AddEntry(h5,"Energy of primary proton: 10^{14} eV");
legend->AddEntry(h4,"Energy of primary proton: 10^{13} eV");
legend->AddEntry(h3,"Energy of primary proton: 10^{12} eV");
legend->Draw();
