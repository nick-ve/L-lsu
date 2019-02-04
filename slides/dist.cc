{
 gSystem->Load("ncfspack");

 Float_t zmin=0;
 Float_t zmax=15;
 Int_t nsteps=50;
 Float_t dz=(zmax-zmin)/float(nsteps);

 TH1F h("h","Physical distance vs. redshift",100,zmin,zmax);
 h.GetXaxis()->SetTitle("Redshift z");
 h.GetYaxis()->SetTitle("Physical Distance in Gpc");
 h.SetMarkerStyle(8);

 NcAstrolab lab;

 Float_t z=0;
 Float_t dist=0;
 for (Int_t i=0; i<nsteps; i++)
 {
  dist=lab.GetPhysicalDistance(z);
  dist*=0.001; // Convert Mpc into Gpc
  h.Fill(z,dist);
  z+=dz;
 }
 h.Draw("P");
}