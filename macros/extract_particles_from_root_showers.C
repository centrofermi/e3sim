void extract_particles_from_root_showers() {
	// Convert root files in ascii
	// to make the analysis with my C++ programs
	char filefrom[40]="DAT_e5GeV-0Th-Fe-0m.root";
	char filedest[40]="shower_e5GeV-0Th-Fe-0m.txt";
	TFile *myfile = new TFile(filefrom,"READ");
        TTree *sim = (TTree*)myfile->Get("sim");
	sim->SetScanField(0);
	freopen(filedest,"w",stdout);
	sim->Scan("particle.x:particle.y:particle.Px:particle.Py:particle.Pz:particle.Time:shower.Energy:shower.Theta","particle.ParticleID==5||particle.ParticleID==6","colsize=12");
	//sim->Scan("particle.x:particle.y:particle.ParticleID:particle.Px:particle.Py:particle.Pz:particle.Time:shower.Energy:shower.Theta","","colsize=12");
	fclose(stdout);
	myfile->Close();
}
