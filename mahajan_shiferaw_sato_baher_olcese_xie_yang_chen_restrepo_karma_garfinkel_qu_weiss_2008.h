/*======================================================================
                                                                        
                      --- DENIS Project ---                             
                        -----------------                               
                                                                        
      Distributed computing                                             
      Electrophysiologycal Models                                       
      Networking colaboration                                           
      In Silico research                                                
      Sharing Knowledge                                                 
                                                                        
------------------------------------------------------------------------
                                                                        
 -- C File of the mahajan_shiferaw_sato_baher_olcese_xie_yang_chen_restrepo_karma_garfinkel_qu_weiss_2008 model created for the DENIS Project -- 
                                                                        
 This file has been automatically created using the CellML API.         
                                                                        
------------------------------------------------------------------------
                                                                        
 DENIS-CellML2C Copyright 2015 J. Carro; J. Castro                      
                                                                        
 Licensed under the Apache License, Version 2.0 (the "License");      
 you may not use this file except in compliance with the License.       
 You may obtain a copy of the License at                                
                                                                        
 http://www.apache.org/licenses/LICENSE-2.0                             
                                                                        
 Unless required by applicable law or agreed to in writing, software    
 distributed under the License is distributed on an "AS IS" BASIS,    
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        
 implied. See the License for the specific language governing           
 permissions and limitations under the License.                         
                                                                        
------------------------------------------------------------------------
                                                                        
                                                  San Jorge University  
                                                 School of Engineering  
                                                                        
                                                     http://eps.usj.es  
                                                                        
======================================================================*/

using namespace std;

namespace mahajan_shiferaw_sato_baher_olcese_xie_yang_chen_restrepo_karma_garfinkel_qu_weiss_2008{

	#define ALGEBRAIC_LENGTH 108
	#define STATE_LENGTH 26
	#define CONSTANT_LENGTH 80 

	double* getNewConstantsArray(){return new double[CONSTANT_LENGTH];}
	double* getNewRatesArray(){return new double[STATE_LENGTH];}
	double* getNewStatesArray(){return new double[STATE_LENGTH];}
	double* getNewAlgebraicArray(){return new double[ALGEBRAIC_LENGTH];}

	
	void getNewArrays(double **constants, double **rates, double **states, double **algebraic){
		*constants = getNewConstantsArray();
		*rates     = getNewRatesArray();
		*states    = getNewStatesArray();
		*algebraic = getNewAlgebraicArray();
	}
	
	void getVectorsLength(int* algebraicLength, int* statesLength, int* constantsLength){
		*algebraicLength = ALGEBRAIC_LENGTH;
		*statesLength = STATE_LENGTH;
		*constantsLength = CONSTANT_LENGTH;
	}
	
	int getNameId(const char* variable, const char* component, const char** names, int namesLength){
		int index = -1;
		int counter = 0;
		string completName(variable);
		completName += " in component ";
		completName += component;
		for(int i=0; i < namesLength; i++){
			if(strncmp(completName.c_str(), names[i], (long)completName.length())==0){
				index = i;
				counter++;
			}
		}
		
		switch(counter){
			case 1:
				return index;
			case 0:
				return -1;
			default:
				return -counter;
		}
	}
		
	void names(const char* &VoI, const char** constants, const char** rates, const char** states, const char** algebraic){
		VoI  = "time in component Environment (ms)";
		constants[0]  = "R in component Environment (J_per_moleK)";
		constants[1]  = "T in component Environment (kelvin)";
		constants[2]  = "F in component Environment (coulomb_per_mmole)";
		constants[3]  = "K_o in component Environment (mM)";
		constants[4]  = "Ca_o in component Environment (mM)";
		constants[5]  = "Na_o in component Environment (mM)";
		constants[75]  = "FonRT in component Environment (per_mV)";
		states[0]  = "V in component cell (mV)";
		algebraic[49]  = "xik1 in component IK1 (nA_per_nF)";
		algebraic[60]  = "xito in component Ito (nA_per_nF)";
		algebraic[65]  = "xiNaK in component INaK (nA_per_nF)";
		constants[6]  = "wca in component cell (mV_per_uM)";
		algebraic[102]  = "xiNaCa in component INaCa (nA_per_nF)";
		algebraic[93]  = "xica in component ICaL (nA_per_nF)";
		algebraic[107]  = "Itotal in component cell (nA_per_nF)";
		algebraic[106]  = "xina in component INa (nA_per_nF)";
		algebraic[51]  = "xikr in component IKr (nA_per_nF)";
		algebraic[104]  = "xiks in component IKs (nA_per_nF)";
		algebraic[10]  = "i_Stim in component cell (nA_per_nF)";
		constants[7]  = "stim_offset in component cell (ms)";
		constants[8]  = "stim_period in component cell (ms)";
		constants[9]  = "stim_duration in component cell (ms)";
		constants[10]  = "stim_amplitude in component cell (nA_per_nF)";
		algebraic[3]  = "past in component cell (ms)";
		algebraic[105]  = "ena in component reversal_potentials (mV)";
		states[1]  = "xm in component INa (dimensionless)";
		states[2]  = "xh in component INa (dimensionless)";
		states[3]  = "xj in component INa (dimensionless)";
		constants[11]  = "gna in component INa (uS_per_nF)";
		algebraic[0]  = "am in component INa (per_ms)";
		algebraic[7]  = "bm in component INa (per_ms)";
		algebraic[1]  = "ah in component INa (per_ms)";
		algebraic[8]  = "bh in component INa (per_ms)";
		algebraic[2]  = "aj in component INa (per_ms)";
		algebraic[9]  = "bj in component INa (per_ms)";
		states[4]  = "Ca_dyad in component Ca (uM)";
		algebraic[88]  = "csm in component Ca (mM)";
		states[5]  = "c1 in component ICaL (dimensionless)";
		states[6]  = "c2 in component ICaL (dimensionless)";
		states[7]  = "xi1ca in component ICaL (dimensionless)";
		states[8]  = "xi1ba in component ICaL (dimensionless)";
		states[9]  = "xi2ca in component ICaL (dimensionless)";
		states[10]  = "xi2ba in component ICaL (dimensionless)";
		constants[12]  = "gca in component ICaL (mmole_per_coulomb_cm)";
		constants[13]  = "pca in component ICaL (cm_per_s)";
		algebraic[14]  = "za in component ICaL (dimensionless)";
		algebraic[18]  = "poinf in component ICaL (dimensionless)";
		algebraic[26]  = "fca in component ICaL (dimensionless)";
		constants[14]  = "vth in component ICaL (mV)";
		constants[15]  = "s6 in component ICaL (mV)";
		constants[16]  = "vx in component ICaL (mV)";
		constants[17]  = "sx in component ICaL (mV)";
		constants[18]  = "vy in component ICaL (mV)";
		constants[19]  = "sy in component ICaL (mV)";
		constants[20]  = "vyr in component ICaL (mV)";
		constants[21]  = "syr in component ICaL (mV)";
		constants[22]  = "cat in component ICaL (uM)";
		constants[23]  = "cpt in component ICaL (uM)";
		algebraic[23]  = "alpha in component ICaL (per_ms)";
		algebraic[25]  = "beta in component ICaL (per_ms)";
		algebraic[28]  = "k1 in component ICaL (per_ms)";
		constants[24]  = "k2 in component ICaL (per_ms)";
		constants[25]  = "k1t in component ICaL (per_ms)";
		constants[26]  = "k2t in component ICaL (per_ms)";
		algebraic[31]  = "k3 in component ICaL (per_ms)";
		algebraic[32]  = "k3t in component ICaL (per_ms)";
		algebraic[39]  = "k6 in component ICaL (per_ms)";
		algebraic[40]  = "k5 in component ICaL (per_ms)";
		algebraic[41]  = "k6t in component ICaL (per_ms)";
		algebraic[42]  = "k5t in component ICaL (per_ms)";
		algebraic[43]  = "k4 in component ICaL (per_ms)";
		algebraic[44]  = "k4t in component ICaL (per_ms)";
		constants[27]  = "r1 in component ICaL (per_ms)";
		constants[28]  = "r2 in component ICaL (per_ms)";
		algebraic[27]  = "s1 in component ICaL (per_ms)";
		constants[29]  = "s1t in component ICaL (per_ms)";
		algebraic[29]  = "s2 in component ICaL (per_ms)";
		constants[76]  = "s2t in component ICaL (per_ms)";
		algebraic[34]  = "recov in component ICaL (ms)";
		constants[30]  = "tca in component ICaL (ms)";
		algebraic[35]  = "tau_ca in component ICaL (ms)";
		algebraic[36]  = "tauca in component ICaL (ms)";
		algebraic[37]  = "tauba in component ICaL (ms)";
		constants[31]  = "taupo in component ICaL (ms)";
		constants[32]  = "tau3 in component ICaL (ms)";
		algebraic[33]  = "Pr in component ICaL (dimensionless)";
		algebraic[38]  = "Ps in component ICaL (dimensionless)";
		algebraic[30]  = "poi in component ICaL (dimensionless)";
		algebraic[45]  = "po in component ICaL (dimensionless)";
		algebraic[89]  = "rxa in component ICaL (mA_per_cm2)";
		algebraic[90]  = "jca in component ICaL (uM_per_ms)";
		constants[79]  = "ek in component reversal_potentials (mV)";
		constants[33]  = "gkix in component IK1 (uS_per_nF)";
		algebraic[46]  = "aki in component IK1 (per_ms)";
		algebraic[47]  = "bki in component IK1 (per_ms)";
		algebraic[48]  = "xkin in component IK1 (dimensionless)";
		states[11]  = "xr in component IKr (dimensionless)";
		constants[34]  = "gkr in component IKr (uS_per_nF)";
		algebraic[4]  = "xkrv1 in component IKr (per_ms)";
		algebraic[11]  = "xkrv2 in component IKr (per_ms)";
		algebraic[15]  = "taukr in component IKr (ms)";
		algebraic[19]  = "xkrinf in component IKr (dimensionless)";
		algebraic[50]  = "rg in component IKr (dimensionless)";
		states[12]  = "Ca_i in component Ca (uM)";
		constants[35]  = "gks in component IKs (uS_per_nF)";
		states[13]  = "xs1 in component IKs (dimensionless)";
		states[14]  = "xs2 in component IKs (dimensionless)";
		algebraic[103]  = "eks in component reversal_potentials (mV)";
		algebraic[5]  = "xs1ss in component IKs (dimensionless)";
		algebraic[12]  = "xs2ss in component IKs (dimensionless)";
		algebraic[16]  = "tauxs1 in component IKs (ms)";
		algebraic[20]  = "tauxs2 in component IKs (ms)";
		algebraic[52]  = "gksx in component IKs (dimensionless)";
		algebraic[56]  = "xitos in component Ito (nA_per_nF)";
		algebraic[58]  = "xitof in component Ito (nA_per_nF)";
		states[15]  = "xtos in component Ito (dimensionless)";
		states[16]  = "ytos in component Ito (dimensionless)";
		states[17]  = "xtof in component Ito (dimensionless)";
		states[18]  = "ytof in component Ito (dimensionless)";
		constants[36]  = "gtos in component Ito (uS_per_nF)";
		constants[37]  = "gtof in component Ito (uS_per_nF)";
		algebraic[6]  = "rt1 in component Ito (dimensionless)";
		algebraic[53]  = "rt2 in component Ito (dimensionless)";
		algebraic[55]  = "rt3 in component Ito (dimensionless)";
		algebraic[13]  = "rt4 in component Ito (dimensionless)";
		algebraic[57]  = "rt5 in component Ito (dimensionless)";
		algebraic[17]  = "xtos_inf in component Ito (dimensionless)";
		algebraic[59]  = "ytos_inf in component Ito (dimensionless)";
		algebraic[21]  = "xtof_inf in component Ito (dimensionless)";
		algebraic[61]  = "ytof_inf in component Ito (dimensionless)";
		algebraic[54]  = "rs_inf in component Ito (dimensionless)";
		algebraic[22]  = "txs in component Ito (ms)";
		algebraic[62]  = "tys in component Ito (ms)";
		algebraic[24]  = "txf in component Ito (ms)";
		algebraic[64]  = "tyf in component Ito (ms)";
		states[19]  = "Na_i in component Na (mM)";
		constants[38]  = "gNaK in component INaK (nA_per_nF)";
		constants[39]  = "xkmko in component INaK (mM)";
		constants[40]  = "xkmnai in component INaK (mM)";
		constants[77]  = "sigma in component INaK (dimensionless)";
		algebraic[63]  = "fNaK in component INaK (dimensionless)";
		states[20]  = "Ca_submem in component Ca (uM)";
		constants[41]  = "gNaCa in component INaCa (uM_per_ms)";
		algebraic[67]  = "aloss in component INaCa (dimensionless)";
		algebraic[97]  = "yz1 in component INaCa (mM4)";
		algebraic[98]  = "yz2 in component INaCa (mM4)";
		algebraic[68]  = "yz3 in component INaCa (mM4)";
		algebraic[99]  = "yz4 in component INaCa (mM4)";
		algebraic[95]  = "zw3 in component INaCa (mM4)";
		algebraic[66]  = "zw4 in component INaCa (dimensionless)";
		algebraic[100]  = "zw8 in component INaCa (mM4)";
		algebraic[101]  = "jNaCa in component INaCa (uM_per_ms)";
		constants[42]  = "xkdna in component INaCa (uM)";
		constants[43]  = "xmcao in component INaCa (mM)";
		constants[44]  = "xmnao in component INaCa (mM)";
		constants[45]  = "xmnai in component INaCa (mM)";
		constants[46]  = "xmcai in component INaCa (mM)";
		states[21]  = "Ca_NSR in component Ca (uM)";
		algebraic[87]  = "dCa_JSR in component Ca (uM_per_ms)";
		constants[47]  = "cstar in component Irel (uM)";
		states[22]  = "Ca_JSR in component Irel (uM)";
		constants[48]  = "gryr in component Irel (per_ms)";
		constants[49]  = "gbarsr in component Irel (dimensionless)";
		constants[50]  = "gdyad in component Irel (mmole_per_coulomb_cm)";
		constants[51]  = "ax in component Irel (per_mV)";
		constants[52]  = "ay in component Irel (per_mV)";
		constants[53]  = "av in component Irel (per_ms)";
		constants[78]  = "bv in component Irel (uM_per_ms)";
		algebraic[69]  = "Qr0 in component Irel (uM_per_ms)";
		algebraic[70]  = "Qr in component Irel (uM_per_ms)";
		algebraic[71]  = "sparkV in component Irel (dimensionless)";
		algebraic[91]  = "spark_rate in component Irel (per_ms)";
		constants[54]  = "taua in component Irel (ms)";
		constants[55]  = "taur in component Irel (ms)";
		algebraic[92]  = "xirp in component Irel (uM_per_ms)";
		algebraic[94]  = "xicap in component Irel (uM_per_ms)";
		algebraic[96]  = "xiryr in component Irel (uM_per_ms)";
		states[23]  = "xir in component Irel (uM_per_ms)";
		algebraic[72]  = "jup in component Ileak_Iup_Ixfer (uM_per_ms)";
		algebraic[73]  = "jleak in component Ileak_Iup_Ixfer (uM_per_ms)";
		constants[56]  = "cup in component Ileak_Iup_Ixfer (uM)";
		constants[57]  = "kj in component Ileak_Iup_Ixfer (uM)";
		constants[58]  = "vup in component Ileak_Iup_Ixfer (uM_per_ms)";
		constants[59]  = "gleak in component Ileak_Iup_Ixfer (per_ms)";
		constants[60]  = "bcal in component Ca (uM)";
		constants[61]  = "xkcal in component Ca (uM)";
		constants[62]  = "srmax in component Ca (uM)";
		constants[63]  = "srkd in component Ca (uM)";
		constants[64]  = "bmem in component Ca (uM)";
		constants[65]  = "kmem in component Ca (uM)";
		constants[66]  = "bsar in component Ca (uM)";
		constants[67]  = "ksar in component Ca (uM)";
		algebraic[74]  = "bpxs in component Ca (dimensionless)";
		algebraic[75]  = "spxs in component Ca (dimensionless)";
		algebraic[76]  = "mempxs in component Ca (dimensionless)";
		algebraic[77]  = "sarpxs in component Ca (dimensionless)";
		algebraic[78]  = "dcsib in component Ca (dimensionless)";
		algebraic[79]  = "bpxi in component Ca (dimensionless)";
		algebraic[80]  = "spxi in component Ca (dimensionless)";
		algebraic[81]  = "mempxi in component Ca (dimensionless)";
		algebraic[82]  = "sarpxi in component Ca (dimensionless)";
		algebraic[83]  = "dciib in component Ca (dimensionless)";
		constants[68]  = "xkon in component Ca (per_uM_per_ms)";
		constants[69]  = "xkoff in component Ca (per_ms)";
		constants[70]  = "btrop in component Ca (uM)";
		algebraic[86]  = "xbi in component Ca (uM_per_ms)";
		algebraic[85]  = "xbs in component Ca (uM_per_ms)";
		states[24]  = "tropi in component Ca (uM)";
		states[25]  = "trops in component Ca (uM)";
		constants[71]  = "taud in component Ca (ms)";
		constants[72]  = "taups in component Ca (ms)";
		algebraic[84]  = "jd in component Ca (uM_per_ms)";
		constants[73]  = "K_i in component reversal_potentials (mM)";
		constants[74]  = "prNaK in component reversal_potentials (dimensionless)";
		rates[0]  = "d/dt V in component cell (mV)";
		rates[2]  = "d/dt xh in component INa (dimensionless)";
		rates[3]  = "d/dt xj in component INa (dimensionless)";
		rates[1]  = "d/dt xm in component INa (dimensionless)";
		rates[5]  = "d/dt c1 in component ICaL (dimensionless)";
		rates[6]  = "d/dt c2 in component ICaL (dimensionless)";
		rates[7]  = "d/dt xi1ca in component ICaL (dimensionless)";
		rates[8]  = "d/dt xi1ba in component ICaL (dimensionless)";
		rates[9]  = "d/dt xi2ca in component ICaL (dimensionless)";
		rates[10]  = "d/dt xi2ba in component ICaL (dimensionless)";
		rates[11]  = "d/dt xr in component IKr (dimensionless)";
		rates[13]  = "d/dt xs1 in component IKs (dimensionless)";
		rates[14]  = "d/dt xs2 in component IKs (dimensionless)";
		rates[15]  = "d/dt xtos in component Ito (dimensionless)";
		rates[16]  = "d/dt ytos in component Ito (dimensionless)";
		rates[17]  = "d/dt xtof in component Ito (dimensionless)";
		rates[18]  = "d/dt ytof in component Ito (dimensionless)";
		rates[22]  = "d/dt Ca_JSR in component Irel (uM)";
		rates[23]  = "d/dt xir in component Irel (uM_per_ms)";
		rates[19]  = "d/dt Na_i in component Na (mM)";
		rates[4]  = "d/dt Ca_dyad in component Ca (uM)";
		rates[20]  = "d/dt Ca_submem in component Ca (uM)";
		rates[12]  = "d/dt Ca_i in component Ca (uM)";
		rates[21]  = "d/dt Ca_NSR in component Ca (uM)";
		rates[24]  = "d/dt tropi in component Ca (uM)";
		rates[25]  = "d/dt trops in component Ca (uM)";
	}

	void initConsts(double* constants, double* states){
		constants[0] = 8.314472;
		constants[1] = 308;
		constants[2] = 96.4853415;
		constants[3] = 5.4;
		constants[4] = 1.8;
		constants[5] = 136;
		states[0] = -87.169816169406;
		constants[6] = 8;
		constants[7] = 0;
		constants[8] = 400;
		constants[9] = 3;
		constants[10] = -15;
		states[1] = 0.001075453357;
		states[2] = 0.990691306716;
		states[3] = 0.993888937283;
		constants[11] = 12;
		states[4] = 1.716573130685;
		states[5] = 0.000018211252;
		states[6] = 0.979322592773;
		states[7] = 0.001208153482;
		states[8] = 0.000033616596;
		states[9] = 0.004173008466;
		states[10] = 0.015242594688;
		constants[12] = 182;
		constants[13] = 0.00054;
		constants[14] = 0;
		constants[15] = 8;
		constants[16] = -40;
		constants[17] = 3;
		constants[18] = -40;
		constants[19] = 4;
		constants[20] = -40;
		constants[21] = 11.32;
		constants[22] = 3;
		constants[23] = 6.09365;
		constants[24] = 1.03615e-4;
		constants[25] = 0.00413;
		constants[26] = 0.00224;
		constants[27] = 0.3;
		constants[28] = 3;
		constants[29] = 0.00195;
		constants[30] = 78.0329;
		constants[31] = 1;
		constants[32] = 3;
		constants[33] = 0.3;
		states[11] = 0.007074239331;
		constants[34] = 0.0125;
		states[12] = 0.256752008084;
		constants[35] = 0.1386;
		states[13] = 0.048267587131;
		states[14] = 0.105468807033;
		states[15] = 0.00364776906;
		states[16] = 0.174403618112;
		states[17] = 0.003643592594;
		states[18] = 0.993331326442;
		constants[36] = 0.04;
		constants[37] = 0.11;
		states[19] = 11.441712311614;
		constants[38] = 1.5;
		constants[39] = 1.5;
		constants[40] = 12;
		states[20] = 0.226941113355;
		constants[41] = 0.84;
		constants[42] = 0.3;
		constants[43] = 1.3;
		constants[44] = 87.5;
		constants[45] = 12.3;
		constants[46] = 0.0036;
		states[21] = 104.450004990523;
		constants[47] = 90;
		states[22] = 97.505463697266;
		constants[48] = 2.58079;
		constants[49] = 26841.8;
		constants[50] = 9000;
		constants[51] = 0.3576;
		constants[52] = 0.05;
		constants[53] = 11.3;
		constants[54] = 100;
		constants[55] = 30;
		states[23] = 0.006679257264;
		constants[56] = 0.5;
		constants[57] = 50;
		constants[58] = 0.4;
		constants[59] = 0.00002069;
		constants[60] = 24;
		constants[61] = 7;
		constants[62] = 47;
		constants[63] = 0.6;
		constants[64] = 15;
		constants[65] = 0.3;
		constants[66] = 42;
		constants[67] = 13;
		constants[68] = 0.0327;
		constants[69] = 0.0196;
		constants[70] = 70;
		states[24] = 22.171689894953;
		states[25] = 19.864701949854;
		constants[71] = 4;
		constants[72] = 0.5;
		constants[73] = 140;
		constants[74] = 0.01833;
		constants[75] = constants[2]/( constants[0]*constants[1]);
		constants[76] = ( (( constants[29]*constants[27])/constants[28])*constants[26])/constants[25];
		constants[77] = (exp(constants[5]/67.3000) - 1.00000)/7.00000;
		constants[78] =  (1.00000 - constants[53])*constants[47] - 50.0000;
		constants[79] =  (1.00000/constants[75])*log(constants[3]/constants[73]);
	}

	void computeRates(double VoI, double* constants, double* rates, double* states, double* algebraic){
		rates[22] = (states[21] - states[22])/constants[54];
		algebraic[1] = (states[0]<- 40.0000 ?  0.135000*exp((80.0000+states[0])/- 6.80000) : 0.00000);
		algebraic[8] = (states[0]<- 40.0000 ?  3.56000*exp( 0.0790000*states[0])+ 310000.*exp( 0.350000*states[0]) : 1.00000/( 0.130000*(1.00000+exp((states[0]+10.6600)/- 11.1000))));
		rates[2] =  algebraic[1]*(1.00000 - states[2]) -  algebraic[8]*states[2];
		algebraic[2] = (states[0]<- 40.0000 ? ( ( - 127140.*exp( 0.244400*states[0]) -  3.47400e-05*exp( - 0.0439100*states[0]))*1.00000*(states[0]+37.7800))/(1.00000+exp( 0.311000*(states[0]+79.2300))) : 0.00000);
		algebraic[9] = (states[0]<- 40.0000 ? ( 0.121200*exp( - 0.0105200*states[0]))/(1.00000+exp( - 0.137800*(states[0]+40.1400))) : ( 0.300000*exp( - 2.53500e-07*states[0]))/(1.00000+exp( - 0.100000*(states[0]+32.0000))));
		rates[3] =  algebraic[2]*(1.00000 - states[3]) -  algebraic[9]*states[3];
		algebraic[0] = (fabs(states[0]+47.1300)>0.00100000 ? ( 0.320000*1.00000*(states[0]+47.1300))/(1.00000 - exp( - 0.100000*(states[0]+47.1300))) : 3.20000);
		algebraic[7] =  0.0800000*exp(- states[0]/11.0000);
		rates[1] =  algebraic[0]*(1.00000 - states[1]) -  algebraic[7]*states[1];
		algebraic[5] = 1.00000/(1.00000+exp(- (states[0] - 1.50000)/16.7000));
		algebraic[16] = (fabs(states[0]+30.0000)<0.00100000/0.0687000 ? 1.00000/(7.19000e-05/0.148000+0.000131000/0.0687000) : 1.00000/(( 7.19000e-05*(states[0]+30.0000))/(1.00000 - exp( - 0.148000*(states[0]+30.0000)))+( 0.000131000*(states[0]+30.0000))/(exp( 0.0687000*(states[0]+30.0000)) - 1.00000)));
		rates[13] = (algebraic[5] - states[13])/algebraic[16];
		algebraic[4] = (fabs(states[0]+7.00000)>0.00100000 ? ( 0.00138000*1.00000*(states[0]+7.00000))/(1.00000 - exp( - 0.123000*(states[0]+7.00000))) : 0.00138000/0.123000);
		algebraic[11] = (fabs(states[0]+10.0000)>0.00100000 ? ( 0.000610000*1.00000*(states[0]+10.0000))/(exp( 0.145000*(states[0]+10.0000)) - 1.00000) : 0.000610000/0.145000);
		algebraic[15] = 1.00000/(algebraic[4]+algebraic[11]);
		algebraic[19] = 1.00000/(1.00000+exp(- (states[0]+50.0000)/7.50000));
		rates[11] = (algebraic[19] - states[11])/algebraic[15];
		algebraic[12] = algebraic[5];
		algebraic[20] =  4.00000*algebraic[16];
		rates[14] = (algebraic[12] - states[14])/algebraic[20];
		algebraic[6] = - (states[0]+3.00000)/15.0000;
		algebraic[17] = 1.00000/(1.00000+exp(algebraic[6]));
		algebraic[22] = 9.00000/(1.00000+exp(- algebraic[6]))+0.500000;
		rates[15] = (algebraic[17] - states[15])/algebraic[22];
		algebraic[21] = algebraic[17];
		algebraic[13] = ( (- states[0]/30.0000)*states[0])/30.0000;
		algebraic[24] =  3.50000*exp(algebraic[13])+1.50000;
		rates[17] = (algebraic[21] - states[17])/algebraic[24];
		algebraic[18] = 1.00000/(1.00000+exp(- (states[0] - constants[14])/constants[15]));
		algebraic[23] = algebraic[18]/constants[31];
		algebraic[25] = (1.00000 - algebraic[18])/constants[31];
		algebraic[26] = 1.00000/(1.00000+pow(constants[22]/states[4], 3.00000));
		algebraic[34] = 10.0000+ 4954.00*exp(states[0]/15.6000);
		algebraic[35] = constants[30]/(1.00000+pow(states[4]/constants[23], 4.00000))+0.100000;
		algebraic[33] = 1.00000 - 1.00000/(1.00000+exp(- (states[0] - constants[18])/constants[19]));
		algebraic[36] =  (algebraic[34] - algebraic[35])*algebraic[33]+algebraic[35];
		algebraic[38] = 1.00000/(1.00000+exp(- (states[0] - constants[20])/constants[21]));
		algebraic[39] = ( algebraic[26]*algebraic[38])/algebraic[36];
		algebraic[40] = (1.00000 - algebraic[38])/algebraic[36];
		algebraic[37] =  (algebraic[34] - 450.000)*algebraic[33]+450.000;
		algebraic[41] = algebraic[38]/algebraic[37];
		algebraic[42] = (1.00000 - algebraic[38])/algebraic[37];
		rates[6] = ( algebraic[25]*states[5]+ algebraic[40]*states[9]+ algebraic[42]*states[10]) -  (algebraic[39]+algebraic[41]+algebraic[23])*states[6];
		algebraic[30] = 1.00000/(1.00000+exp(- (states[0] - constants[16])/constants[17]));
		algebraic[31] = (1.00000 - algebraic[30])/constants[32];
		algebraic[28] =  0.0241680*algebraic[26];
		algebraic[43] = ( (( (( algebraic[31]*algebraic[23])/algebraic[25])*algebraic[28])/constants[24])*algebraic[40])/algebraic[39];
		rates[9] = ( algebraic[31]*states[7]+ algebraic[39]*states[6]) -  (algebraic[40]+algebraic[43])*states[9];
		algebraic[32] = algebraic[31];
		algebraic[44] = ( (( (( algebraic[32]*algebraic[23])/algebraic[25])*constants[25])/constants[26])*algebraic[42])/algebraic[41];
		rates[10] = ( algebraic[32]*states[8]+ algebraic[41]*states[6]) -  (algebraic[42]+algebraic[44])*states[10];
		algebraic[45] = (((((1.00000 - states[7]) - states[9]) - states[8]) - states[10]) - states[5]) - states[6];
		rates[5] = ( algebraic[23]*states[6]+ constants[24]*states[7]+ constants[26]*states[8]+ constants[28]*algebraic[45]) -  (algebraic[25]+constants[27]+constants[25]+algebraic[28])*states[5];
		algebraic[27] =  0.0182688*algebraic[26];
		algebraic[29] = ( (( algebraic[27]*constants[27])/constants[28])*constants[24])/algebraic[28];
		rates[7] = ( algebraic[28]*states[5]+ algebraic[43]*states[9]+ algebraic[27]*algebraic[45]) -  (algebraic[31]+constants[24]+algebraic[29])*states[7];
		rates[8] = ( constants[25]*states[5]+ algebraic[44]*states[10]+ constants[29]*algebraic[45]) -  (algebraic[32]+constants[26]+constants[76])*states[8];
		algebraic[53] = (states[0]+33.5000)/10.0000;
		algebraic[59] = 1.00000/(1.00000+exp(algebraic[53]));
		algebraic[55] = (states[0]+60.0000)/10.0000;
		algebraic[62] = 3000.00/(1.00000+exp(algebraic[55]))+30.0000;
		rates[16] = (algebraic[59] - states[16])/algebraic[62];
		algebraic[61] = algebraic[59];
		algebraic[57] = (states[0]+33.5000)/10.0000;
		algebraic[64] = 20.0000/(1.00000+exp(algebraic[57]))+20.0000;
		rates[18] = (algebraic[61] - states[18])/algebraic[64];
		algebraic[72] = ( constants[58]*states[12]*states[12])/( states[12]*states[12]+ constants[56]*constants[56]);
		algebraic[73] =  (( constants[59]*states[21]*states[21])/( states[21]*states[21]+ constants[57]*constants[57]))*( states[21]*16.6670 - states[12]);
		algebraic[79] = ( constants[60]*constants[61])/( (constants[61]+states[12])*(constants[61]+states[12]));
		algebraic[80] = ( constants[62]*constants[63])/( (constants[63]+states[12])*(constants[63]+states[12]));
		algebraic[81] = ( constants[64]*constants[65])/( (constants[65]+states[12])*(constants[65]+states[12]));
		algebraic[82] = ( constants[66]*constants[67])/( (constants[67]+states[12])*(constants[67]+states[12]));
		algebraic[83] = 1.00000/(1.00000+algebraic[79]+algebraic[80]+algebraic[81]+algebraic[82]);
		algebraic[86] =  constants[68]*states[12]*(constants[70] - states[24]) -  constants[69]*states[24];
		algebraic[84] = (states[20] - states[12])/constants[71];
		rates[12] =  algebraic[83]*(((algebraic[84] - algebraic[72])+algebraic[73]) - algebraic[86]);
		rates[24] = algebraic[86];
		algebraic[85] =  constants[68]*states[20]*(constants[70] - states[25]) -  constants[69]*states[25];
		rates[25] = algebraic[85];
		algebraic[87] = (- states[23]+algebraic[72]) - algebraic[73];
		rates[21] = algebraic[87];
		algebraic[69] = (states[22]>50.0000&&states[22]<constants[47] ? (states[22] - 50.0000)/1.00000 : states[22]>=constants[47] ?  constants[53]*states[22]+constants[78] : 0.00000);
		algebraic[70] = ( states[21]*algebraic[69])/constants[47];
		algebraic[88] = states[20]/1000.00;
		algebraic[14] =  states[0]*2.00000*constants[75];
		algebraic[89] = (fabs(algebraic[14])<0.00100000 ? ( 4.00000*constants[13]*constants[2]*constants[75]*( algebraic[88]*exp(algebraic[14]) -  0.341000*constants[4]))/( 2.00000*constants[75]) : ( 4.00000*constants[13]*states[0]*constants[2]*constants[75]*( algebraic[88]*exp(algebraic[14]) -  0.341000*constants[4]))/(exp(algebraic[14]) - 1.00000));
		algebraic[71] = exp( - constants[52]*(states[0]+30.0000))/(1.00000+exp( - constants[52]*(states[0]+30.0000)));
		algebraic[91] =  (constants[48]/1.00000)*algebraic[45]*fabs(algebraic[89])*algebraic[71];
		rates[23] =  algebraic[91]*algebraic[70] - ( states[23]*(1.00000 - ( constants[55]*algebraic[87])/states[21]))/constants[55];
		algebraic[92] = ( (( algebraic[45]*algebraic[70]*fabs(algebraic[89])*constants[49])/1.00000)*exp( - constants[51]*(states[0]+30.0000)))/(1.00000+exp( - constants[51]*(states[0]+30.0000)));
		algebraic[94] =  algebraic[45]*constants[50]*fabs(algebraic[89]);
		algebraic[96] = algebraic[92]+algebraic[94];
		rates[4] = algebraic[96] - (states[4] - states[20])/constants[72];
		algebraic[90] =  constants[12]*algebraic[45]*algebraic[89];
		algebraic[67] = 1.00000/(1.00000+pow(constants[42]/states[20], 3.00000));
		algebraic[95] =  pow(states[19], 3.00000)*constants[4]*exp( states[0]*0.350000*constants[75]) -  pow(constants[5], 3.00000)*algebraic[88]*exp( states[0]*(0.350000 - 1.00000)*constants[75]);
		algebraic[66] = 1.00000+ 0.200000*exp( states[0]*(0.350000 - 1.00000)*constants[75]);
		algebraic[97] =  constants[43]*pow(states[19], 3.00000)+ pow(constants[44], 3.00000)*algebraic[88];
		algebraic[98] =  pow(constants[45], 3.00000)*constants[4]*(1.00000+algebraic[88]/constants[46]);
		algebraic[68] =  constants[46]*pow(constants[5], 3.00000)*(1.00000+pow(states[19]/constants[45], 3.00000));
		algebraic[99] =  pow(states[19], 3.00000)*constants[4]+ pow(constants[5], 3.00000)*algebraic[88];
		algebraic[100] = algebraic[97]+algebraic[98]+algebraic[68]+algebraic[99];
		algebraic[101] = ( constants[41]*algebraic[67]*algebraic[95])/( algebraic[66]*algebraic[100]);
		algebraic[74] = ( constants[60]*constants[61])/( (constants[61]+states[20])*(constants[61]+states[20]));
		algebraic[75] = ( constants[62]*constants[63])/( (constants[63]+states[20])*(constants[63]+states[20]));
		algebraic[76] = ( constants[64]*constants[65])/( (constants[65]+states[20])*(constants[65]+states[20]));
		algebraic[77] = ( constants[66]*constants[67])/( (constants[67]+states[20])*(constants[67]+states[20]));
		algebraic[78] = 1.00000/(1.00000+algebraic[74]+algebraic[75]+algebraic[76]+algebraic[77]);
		rates[20] =  algebraic[78]*( 50.0000*(((states[23] - algebraic[84]) - algebraic[90])+algebraic[101]) - algebraic[85]);
		algebraic[63] = 1.00000/(1.00000+ 0.124500*exp( - 0.100000*states[0]*constants[75])+ 0.0365000*constants[77]*exp( - states[0]*constants[75]));
		algebraic[65] = ( (( constants[38]*algebraic[63]*states[19])/(states[19]+constants[40]))*constants[3])/(constants[3]+constants[39]);
		algebraic[102] =  constants[6]*algebraic[101];
		algebraic[105] =  (1.00000/constants[75])*log(constants[5]/states[19]);
		algebraic[106] =  constants[11]*states[2]*states[3]*states[1]*states[1]*states[1]*(states[0] - algebraic[105]);
		rates[19] = - (algebraic[106]+ 3.00000*algebraic[65]+ 3.00000*algebraic[102])/( constants[6]*1000.00);
		algebraic[46] = 1.02000/(1.00000+exp( 0.238500*((states[0] - constants[79]) - 59.2150)));
		algebraic[47] = ( 0.491240*exp( 0.0803200*((states[0] - constants[79])+5.47600))+ 1.00000*exp( 0.0617500*((states[0] - constants[79]) - 594.310)))/(1.00000+exp( - 0.514300*((states[0] - constants[79])+4.75300)));
		algebraic[48] = algebraic[46]/(algebraic[46]+algebraic[47]);
		algebraic[49] =  constants[33]* pow((constants[3]/5.40000), 1.0 / 2)*algebraic[48]*(states[0] - constants[79]);
		algebraic[54] = 1.00000/(1.00000+exp(algebraic[53]));
		algebraic[56] =  constants[36]*states[15]*(states[16]+ 0.500000*algebraic[54])*(states[0] - constants[79]);
		algebraic[58] =  constants[37]*states[17]*states[18]*(states[0] - constants[79]);
		algebraic[60] = algebraic[56]+algebraic[58];
		algebraic[93] =  2.00000*constants[6]*algebraic[90];
		algebraic[50] = 1.00000/(1.00000+exp((states[0]+33.0000)/22.4000));
		algebraic[51] =  constants[34]* pow((constants[3]/5.40000), 1.0 / 2)*states[11]*algebraic[50]*(states[0] - constants[79]);
		algebraic[103] =  (1.00000/constants[75])*log((constants[3]+ constants[74]*constants[5])/(constants[73]+ constants[74]*states[19]));
		algebraic[52] = 1.00000+0.800000/(1.00000+pow(0.500000/states[12], 3.00000));
		algebraic[104] =  constants[35]*algebraic[52]*states[13]*states[14]*(states[0] - algebraic[103]);
		algebraic[3] =  floor(VoI/constants[8])*constants[8];
		algebraic[10] = (VoI - algebraic[3]>=constants[7]&&VoI - algebraic[3]<=constants[7]+constants[9] ? constants[10] : 0.00000);
		algebraic[107] = - (algebraic[106]+algebraic[49]+algebraic[51]+algebraic[104]+algebraic[60]+algebraic[102]+algebraic[93]+algebraic[65]+algebraic[10]);
		rates[0] = algebraic[107];
	}

	void computeVariables(double VoI, double* constants, double* rates, double* states, double* algebraic){
		algebraic[1] = (states[0]<- 40.0000 ?  0.135000*exp((80.0000+states[0])/- 6.80000) : 0.00000);
		algebraic[8] = (states[0]<- 40.0000 ?  3.56000*exp( 0.0790000*states[0])+ 310000.*exp( 0.350000*states[0]) : 1.00000/( 0.130000*(1.00000+exp((states[0]+10.6600)/- 11.1000))));
		algebraic[2] = (states[0]<- 40.0000 ? ( ( - 127140.*exp( 0.244400*states[0]) -  3.47400e-05*exp( - 0.0439100*states[0]))*1.00000*(states[0]+37.7800))/(1.00000+exp( 0.311000*(states[0]+79.2300))) : 0.00000);
		algebraic[9] = (states[0]<- 40.0000 ? ( 0.121200*exp( - 0.0105200*states[0]))/(1.00000+exp( - 0.137800*(states[0]+40.1400))) : ( 0.300000*exp( - 2.53500e-07*states[0]))/(1.00000+exp( - 0.100000*(states[0]+32.0000))));
		algebraic[0] = (fabs(states[0]+47.1300)>0.00100000 ? ( 0.320000*1.00000*(states[0]+47.1300))/(1.00000 - exp( - 0.100000*(states[0]+47.1300))) : 3.20000);
		algebraic[7] =  0.0800000*exp(- states[0]/11.0000);
		algebraic[5] = 1.00000/(1.00000+exp(- (states[0] - 1.50000)/16.7000));
		algebraic[16] = (fabs(states[0]+30.0000)<0.00100000/0.0687000 ? 1.00000/(7.19000e-05/0.148000+0.000131000/0.0687000) : 1.00000/(( 7.19000e-05*(states[0]+30.0000))/(1.00000 - exp( - 0.148000*(states[0]+30.0000)))+( 0.000131000*(states[0]+30.0000))/(exp( 0.0687000*(states[0]+30.0000)) - 1.00000)));
		algebraic[4] = (fabs(states[0]+7.00000)>0.00100000 ? ( 0.00138000*1.00000*(states[0]+7.00000))/(1.00000 - exp( - 0.123000*(states[0]+7.00000))) : 0.00138000/0.123000);
		algebraic[11] = (fabs(states[0]+10.0000)>0.00100000 ? ( 0.000610000*1.00000*(states[0]+10.0000))/(exp( 0.145000*(states[0]+10.0000)) - 1.00000) : 0.000610000/0.145000);
		algebraic[15] = 1.00000/(algebraic[4]+algebraic[11]);
		algebraic[19] = 1.00000/(1.00000+exp(- (states[0]+50.0000)/7.50000));
		algebraic[12] = algebraic[5];
		algebraic[20] =  4.00000*algebraic[16];
		algebraic[6] = - (states[0]+3.00000)/15.0000;
		algebraic[17] = 1.00000/(1.00000+exp(algebraic[6]));
		algebraic[22] = 9.00000/(1.00000+exp(- algebraic[6]))+0.500000;
		algebraic[21] = algebraic[17];
		algebraic[13] = ( (- states[0]/30.0000)*states[0])/30.0000;
		algebraic[24] =  3.50000*exp(algebraic[13])+1.50000;
		algebraic[18] = 1.00000/(1.00000+exp(- (states[0] - constants[14])/constants[15]));
		algebraic[23] = algebraic[18]/constants[31];
		algebraic[25] = (1.00000 - algebraic[18])/constants[31];
		algebraic[26] = 1.00000/(1.00000+pow(constants[22]/states[4], 3.00000));
		algebraic[34] = 10.0000+ 4954.00*exp(states[0]/15.6000);
		algebraic[35] = constants[30]/(1.00000+pow(states[4]/constants[23], 4.00000))+0.100000;
		algebraic[33] = 1.00000 - 1.00000/(1.00000+exp(- (states[0] - constants[18])/constants[19]));
		algebraic[36] =  (algebraic[34] - algebraic[35])*algebraic[33]+algebraic[35];
		algebraic[38] = 1.00000/(1.00000+exp(- (states[0] - constants[20])/constants[21]));
		algebraic[39] = ( algebraic[26]*algebraic[38])/algebraic[36];
		algebraic[40] = (1.00000 - algebraic[38])/algebraic[36];
		algebraic[37] =  (algebraic[34] - 450.000)*algebraic[33]+450.000;
		algebraic[41] = algebraic[38]/algebraic[37];
		algebraic[42] = (1.00000 - algebraic[38])/algebraic[37];
		algebraic[30] = 1.00000/(1.00000+exp(- (states[0] - constants[16])/constants[17]));
		algebraic[31] = (1.00000 - algebraic[30])/constants[32];
		algebraic[28] =  0.0241680*algebraic[26];
		algebraic[43] = ( (( (( algebraic[31]*algebraic[23])/algebraic[25])*algebraic[28])/constants[24])*algebraic[40])/algebraic[39];
		algebraic[32] = algebraic[31];
		algebraic[44] = ( (( (( algebraic[32]*algebraic[23])/algebraic[25])*constants[25])/constants[26])*algebraic[42])/algebraic[41];
		algebraic[45] = (((((1.00000 - states[7]) - states[9]) - states[8]) - states[10]) - states[5]) - states[6];
		algebraic[27] =  0.0182688*algebraic[26];
		algebraic[29] = ( (( algebraic[27]*constants[27])/constants[28])*constants[24])/algebraic[28];
		algebraic[53] = (states[0]+33.5000)/10.0000;
		algebraic[59] = 1.00000/(1.00000+exp(algebraic[53]));
		algebraic[55] = (states[0]+60.0000)/10.0000;
		algebraic[62] = 3000.00/(1.00000+exp(algebraic[55]))+30.0000;
		algebraic[61] = algebraic[59];
		algebraic[57] = (states[0]+33.5000)/10.0000;
		algebraic[64] = 20.0000/(1.00000+exp(algebraic[57]))+20.0000;
		algebraic[72] = ( constants[58]*states[12]*states[12])/( states[12]*states[12]+ constants[56]*constants[56]);
		algebraic[73] =  (( constants[59]*states[21]*states[21])/( states[21]*states[21]+ constants[57]*constants[57]))*( states[21]*16.6670 - states[12]);
		algebraic[79] = ( constants[60]*constants[61])/( (constants[61]+states[12])*(constants[61]+states[12]));
		algebraic[80] = ( constants[62]*constants[63])/( (constants[63]+states[12])*(constants[63]+states[12]));
		algebraic[81] = ( constants[64]*constants[65])/( (constants[65]+states[12])*(constants[65]+states[12]));
		algebraic[82] = ( constants[66]*constants[67])/( (constants[67]+states[12])*(constants[67]+states[12]));
		algebraic[83] = 1.00000/(1.00000+algebraic[79]+algebraic[80]+algebraic[81]+algebraic[82]);
		algebraic[86] =  constants[68]*states[12]*(constants[70] - states[24]) -  constants[69]*states[24];
		algebraic[84] = (states[20] - states[12])/constants[71];
		algebraic[85] =  constants[68]*states[20]*(constants[70] - states[25]) -  constants[69]*states[25];
		algebraic[87] = (- states[23]+algebraic[72]) - algebraic[73];
		algebraic[69] = (states[22]>50.0000&&states[22]<constants[47] ? (states[22] - 50.0000)/1.00000 : states[22]>=constants[47] ?  constants[53]*states[22]+constants[78] : 0.00000);
		algebraic[70] = ( states[21]*algebraic[69])/constants[47];
		algebraic[88] = states[20]/1000.00;
		algebraic[14] =  states[0]*2.00000*constants[75];
		algebraic[89] = (fabs(algebraic[14])<0.00100000 ? ( 4.00000*constants[13]*constants[2]*constants[75]*( algebraic[88]*exp(algebraic[14]) -  0.341000*constants[4]))/( 2.00000*constants[75]) : ( 4.00000*constants[13]*states[0]*constants[2]*constants[75]*( algebraic[88]*exp(algebraic[14]) -  0.341000*constants[4]))/(exp(algebraic[14]) - 1.00000));
		algebraic[71] = exp( - constants[52]*(states[0]+30.0000))/(1.00000+exp( - constants[52]*(states[0]+30.0000)));
		algebraic[91] =  (constants[48]/1.00000)*algebraic[45]*fabs(algebraic[89])*algebraic[71];
		algebraic[92] = ( (( algebraic[45]*algebraic[70]*fabs(algebraic[89])*constants[49])/1.00000)*exp( - constants[51]*(states[0]+30.0000)))/(1.00000+exp( - constants[51]*(states[0]+30.0000)));
		algebraic[94] =  algebraic[45]*constants[50]*fabs(algebraic[89]);
		algebraic[96] = algebraic[92]+algebraic[94];
		algebraic[90] =  constants[12]*algebraic[45]*algebraic[89];
		algebraic[67] = 1.00000/(1.00000+pow(constants[42]/states[20], 3.00000));
		algebraic[95] =  pow(states[19], 3.00000)*constants[4]*exp( states[0]*0.350000*constants[75]) -  pow(constants[5], 3.00000)*algebraic[88]*exp( states[0]*(0.350000 - 1.00000)*constants[75]);
		algebraic[66] = 1.00000+ 0.200000*exp( states[0]*(0.350000 - 1.00000)*constants[75]);
		algebraic[97] =  constants[43]*pow(states[19], 3.00000)+ pow(constants[44], 3.00000)*algebraic[88];
		algebraic[98] =  pow(constants[45], 3.00000)*constants[4]*(1.00000+algebraic[88]/constants[46]);
		algebraic[68] =  constants[46]*pow(constants[5], 3.00000)*(1.00000+pow(states[19]/constants[45], 3.00000));
		algebraic[99] =  pow(states[19], 3.00000)*constants[4]+ pow(constants[5], 3.00000)*algebraic[88];
		algebraic[100] = algebraic[97]+algebraic[98]+algebraic[68]+algebraic[99];
		algebraic[101] = ( constants[41]*algebraic[67]*algebraic[95])/( algebraic[66]*algebraic[100]);
		algebraic[74] = ( constants[60]*constants[61])/( (constants[61]+states[20])*(constants[61]+states[20]));
		algebraic[75] = ( constants[62]*constants[63])/( (constants[63]+states[20])*(constants[63]+states[20]));
		algebraic[76] = ( constants[64]*constants[65])/( (constants[65]+states[20])*(constants[65]+states[20]));
		algebraic[77] = ( constants[66]*constants[67])/( (constants[67]+states[20])*(constants[67]+states[20]));
		algebraic[78] = 1.00000/(1.00000+algebraic[74]+algebraic[75]+algebraic[76]+algebraic[77]);
		algebraic[63] = 1.00000/(1.00000+ 0.124500*exp( - 0.100000*states[0]*constants[75])+ 0.0365000*constants[77]*exp( - states[0]*constants[75]));
		algebraic[65] = ( (( constants[38]*algebraic[63]*states[19])/(states[19]+constants[40]))*constants[3])/(constants[3]+constants[39]);
		algebraic[102] =  constants[6]*algebraic[101];
		algebraic[105] =  (1.00000/constants[75])*log(constants[5]/states[19]);
		algebraic[106] =  constants[11]*states[2]*states[3]*states[1]*states[1]*states[1]*(states[0] - algebraic[105]);
		algebraic[46] = 1.02000/(1.00000+exp( 0.238500*((states[0] - constants[79]) - 59.2150)));
		algebraic[47] = ( 0.491240*exp( 0.0803200*((states[0] - constants[79])+5.47600))+ 1.00000*exp( 0.0617500*((states[0] - constants[79]) - 594.310)))/(1.00000+exp( - 0.514300*((states[0] - constants[79])+4.75300)));
		algebraic[48] = algebraic[46]/(algebraic[46]+algebraic[47]);
		algebraic[49] =  constants[33]* pow((constants[3]/5.40000), 1.0 / 2)*algebraic[48]*(states[0] - constants[79]);
		algebraic[54] = 1.00000/(1.00000+exp(algebraic[53]));
		algebraic[56] =  constants[36]*states[15]*(states[16]+ 0.500000*algebraic[54])*(states[0] - constants[79]);
		algebraic[58] =  constants[37]*states[17]*states[18]*(states[0] - constants[79]);
		algebraic[60] = algebraic[56]+algebraic[58];
		algebraic[93] =  2.00000*constants[6]*algebraic[90];
		algebraic[50] = 1.00000/(1.00000+exp((states[0]+33.0000)/22.4000));
		algebraic[51] =  constants[34]* pow((constants[3]/5.40000), 1.0 / 2)*states[11]*algebraic[50]*(states[0] - constants[79]);
		algebraic[103] =  (1.00000/constants[75])*log((constants[3]+ constants[74]*constants[5])/(constants[73]+ constants[74]*states[19]));
		algebraic[52] = 1.00000+0.800000/(1.00000+pow(0.500000/states[12], 3.00000));
		algebraic[104] =  constants[35]*algebraic[52]*states[13]*states[14]*(states[0] - algebraic[103]);
		algebraic[3] =  floor(VoI/constants[8])*constants[8];
		algebraic[10] = (VoI - algebraic[3]>=constants[7]&&VoI - algebraic[3]<=constants[7]+constants[9] ? constants[10] : 0.00000);
		algebraic[107] = - (algebraic[106]+algebraic[49]+algebraic[51]+algebraic[104]+algebraic[60]+algebraic[102]+algebraic[93]+algebraic[65]+algebraic[10]);
	}

};
