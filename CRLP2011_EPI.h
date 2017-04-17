/*======================================================================
                                                                        
                      --- DENIS Project ---                             
                        -----------------                               
                                                                        
      Distributed computing                                             
      Electrophysiologycal Models                                       
      Networking colaboration                                           
      In Silico research                                                
      Sharing Knowledge                                                 
                                                                        
------------------------------------------------------------------------
                                                                        
 -- C File of the CRLP2011_EPI model created for the DENIS Project -- 
                                                                        
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

namespace CRLP2011_EPI{

	#define ALGEBRAIC_LENGTH 118
	#define STATE_LENGTH 43
	#define CONSTANT_LENGTH 110 

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
		VoI  = "t in component environment (millisecond)";
		states[0]  = "V in component membrane (millivolt)";
		constants[0]  = "R in component membrane (joule_per_kmole_kelvin)";
		constants[1]  = "T in component membrane (kelvin)";
		constants[2]  = "Frdy in component membrane (coulomb_per_mole)";
		constants[94]  = "FoRT in component membrane (per_milliV)";
		constants[3]  = "C_mem in component membrane (farad)";
		algebraic[96]  = "I_Na_tot_junc in component Sodium_Concentrations (picoA_per_picoF)";
		algebraic[102]  = "I_Na_tot_sl in component Sodium_Concentrations (picoA_per_picoF)";
		algebraic[57]  = "I_ClCa in component Ca_Activated_Cl_Current (picoA_per_picoF)";
		algebraic[58]  = "I_Cl_Bk in component Background_Cl_Current (picoA_per_picoF)";
		algebraic[111]  = "I_Ca_tot_junc in component Calcium_Concentrations (picoA_per_picoF)";
		algebraic[114]  = "I_Ca_tot_sl in component Calcium_Concentrations (picoA_per_picoF)";
		algebraic[108]  = "I_K_tot in component Potassium_Concentrations (picoA_per_picoF)";
		algebraic[103]  = "I_Na_tot in component membrane (picoA_per_picoF)";
		algebraic[59]  = "I_Cl_tot in component membrane (picoA_per_picoF)";
		algebraic[116]  = "I_Ca_tot in component membrane (picoA_per_picoF)";
		algebraic[117]  = "I_tot in component membrane (picoA_per_picoF)";
		algebraic[10]  = "I_Stim in component membrane (picoA_per_picoF)";
		constants[4]  = "I_Stim_Start in component membrane (millisecond)";
		constants[5]  = "I_Stim_Amplitude in component membrane (picoA_per_picoF)";
		constants[6]  = "I_Stim_Period in component membrane (millisecond)";
		constants[7]  = "I_Stim_PulseDuration in component membrane (millisecond)";
		constants[8]  = "F_junc in component membrane (dimensionless)";
		constants[95]  = "F_sl in component membrane (dimensionless)";
		constants[9]  = "F_junc_Ca_L in component membrane (dimensionless)";
		constants[96]  = "F_sl_Ca_L in component membrane (dimensionless)";
		constants[97]  = "V_cell in component membrane (litre)";
		constants[10]  = "Length_cell in component membrane (decimetre)";
		constants[11]  = "Radius_cell in component membrane (decimetre)";
		constants[99]  = "V_myo in component membrane (litre)";
		constants[102]  = "V_sl in component membrane (litre)";
		constants[103]  = "V_sr in component membrane (litre)";
		constants[104]  = "V_junc in component membrane (litre)";
		constants[12]  = "J_Ca_juncsl in component membrane (L_per_millis)";
		constants[13]  = "J_Ca_slmyo in component membrane (L_per_millis)";
		constants[14]  = "J_Na_juncsl in component membrane (L_per_millis)";
		constants[15]  = "J_Na_slmyo in component membrane (L_per_millis)";
		states[1]  = "Int_I_Na_tot in component membrane (picoA_ms_per_picoF)";
		states[2]  = "Int_I_Cl_tot in component membrane (picoA_ms_per_picoF)";
		states[3]  = "Int_I_Ca_tot in component membrane (picoA_ms_per_picoF)";
		states[4]  = "Int_I_K_tot in component membrane (picoA_ms_per_picoF)";
		algebraic[94]  = "I_Na_junc in component Fast_Na_Current (picoA_per_picoF)";
		algebraic[98]  = "I_Na_sl in component Fast_Na_Current (picoA_per_picoF)";
		algebraic[99]  = "I_Na in component Fast_Na_Current (picoA_per_picoF)";
		algebraic[97]  = "E_Na_sl in component Nerst_Potentials (millivolt)";
		algebraic[93]  = "E_Na_junc in component Nerst_Potentials (millivolt)";
		constants[16]  = "G_Na in component Fast_Na_Current (milliS_per_microF)";
		states[5]  = "m in component Fast_Na_Current (dimensionless)";
		algebraic[0]  = "m_ss in component Fast_Na_Current (dimensionless)";
		algebraic[12]  = "tau_m in component Fast_Na_Current (millisecond)";
		algebraic[1]  = "a_h in component Fast_Na_Current (dimensionless)";
		algebraic[13]  = "b_h in component Fast_Na_Current (dimensionless)";
		algebraic[26]  = "inv_tau_h in component Fast_Na_Current (per_millis)";
		states[6]  = "h in component Fast_Na_Current (dimensionless)";
		algebraic[33]  = "h_ss in component Fast_Na_Current (dimensionless)";
		algebraic[2]  = "a_j in component Fast_Na_Current (dimensionless)";
		algebraic[14]  = "b_j in component Fast_Na_Current (dimensionless)";
		algebraic[27]  = "inv_tau_j in component Fast_Na_Current (per_millis)";
		states[7]  = "j in component Fast_Na_Current (dimensionless)";
		algebraic[34]  = "j_ss in component Fast_Na_Current (dimensionless)";
		algebraic[95]  = "I_Na_Bk_junc in component Background_Na_Current (picoA_per_picoF)";
		algebraic[100]  = "I_Na_Bk_sl in component Background_Na_Current (picoA_per_picoF)";
		algebraic[101]  = "I_Na_Bk in component Background_Na_Current (picoA_per_picoF)";
		constants[17]  = "G_Na_B in component Background_Na_Current (milliS_per_microF)";
		constants[18]  = "Na_o in component Sodium_Concentrations (millimolar)";
		constants[98]  = "sigma in component Na_K_Pump_Current (dimensionless)";
		algebraic[24]  = "f_NaK in component Na_K_Pump_Current (dimensionless)";
		algebraic[31]  = "I_NaK_junc in component Na_K_Pump_Current (picoA_per_picoF)";
		algebraic[38]  = "I_NaK_sl in component Na_K_Pump_Current (picoA_per_picoF)";
		algebraic[43]  = "I_NaK in component Na_K_Pump_Current (picoA_per_picoF)";
		constants[19]  = "Ibar_NaK in component Na_K_Pump_Current (picoA_per_picoF)";
		constants[20]  = "K_o in component Potassium_Concentrations (millimolar)";
		states[8]  = "Na_j in component Sodium_Concentrations (millimolar)";
		states[9]  = "Na_sl in component Sodium_Concentrations (millimolar)";
		constants[21]  = "Km_Ko in component Na_K_Pump_Current (millimolar)";
		constants[22]  = "Km_Naip in component Na_K_Pump_Current (millimolar)";
		algebraic[3]  = "x_r_ss in component Rapidly_Activating_K_Current (dimensionless)";
		states[10]  = "x_Kr in component Rapidly_Activating_K_Current (dimensionless)";
		algebraic[44]  = "r_Kr in component Rapidly_Activating_K_Current (dimensionless)";
		constants[100]  = "E_K in component Nerst_Potentials (millivolt)";
		constants[23]  = "G_Kr in component Rapidly_Activating_K_Current (milliS_per_microF)";
		algebraic[15]  = "tau_xr in component Rapidly_Activating_K_Current (millisecond)";
		algebraic[45]  = "I_Kr in component Rapidly_Activating_K_Current (picoA_per_picoF)";
		algebraic[4]  = "x_s_ss in component Slowly_Activating_K_Current (dimensionless)";
		algebraic[16]  = "inv_tau_xs in component Slowly_Activating_K_Current (per_millis)";
		states[11]  = "x_Ks in component Slowly_Activating_K_Current (dimensionless)";
		algebraic[104]  = "E_Ks in component Nerst_Potentials (millivolt)";
		constants[24]  = "G_Ks_junc in component Slowly_Activating_K_Current (milliS_per_microF)";
		constants[25]  = "G_Ks_sl in component Slowly_Activating_K_Current (milliS_per_microF)";
		algebraic[105]  = "I_Ks_junc in component Slowly_Activating_K_Current (picoA_per_picoF)";
		algebraic[106]  = "I_Ks_sl in component Slowly_Activating_K_Current (picoA_per_picoF)";
		algebraic[107]  = "I_Ks in component Slowly_Activating_K_Current (picoA_per_picoF)";
		algebraic[46]  = "kp_Kp in component Plateau_K_Current (dimensionless)";
		constants[26]  = "G_Kp in component Plateau_K_Current (milliS_per_microF)";
		algebraic[47]  = "I_Kp in component Plateau_K_Current (picoA_per_picoF)";
		algebraic[5]  = "x_to_ss in component Transient_Outward_K_Current (dimensionless)";
		algebraic[6]  = "y_to_ss in component Transient_Outward_K_Current (dimensionless)";
		algebraic[17]  = "tau_x_tos in component Transient_Outward_K_Current (millisecond)";
		algebraic[18]  = "tau_y_tos in component Transient_Outward_K_Current (millisecond)";
		algebraic[19]  = "tau_x_tof in component Transient_Outward_K_Current (millisecond)";
		algebraic[20]  = "tau_y_tof in component Transient_Outward_K_Current (millisecond)";
		states[12]  = "x_to_s in component Transient_Outward_K_Current (dimensionless)";
		states[13]  = "y_to_s in component Transient_Outward_K_Current (dimensionless)";
		states[14]  = "x_to_f in component Transient_Outward_K_Current (dimensionless)";
		states[15]  = "y_to_f in component Transient_Outward_K_Current (dimensionless)";
		constants[27]  = "G_to_s in component Transient_Outward_K_Current (milliS_per_microF)";
		constants[28]  = "G_to_f in component Transient_Outward_K_Current (milliS_per_microF)";
		algebraic[48]  = "I_to_s in component Transient_Outward_K_Current (picoA_per_picoF)";
		algebraic[49]  = "I_to_f in component Transient_Outward_K_Current (picoA_per_picoF)";
		algebraic[50]  = "I_to in component Transient_Outward_K_Current (picoA_per_picoF)";
		algebraic[51]  = "a_K1 in component Inward_Rectifier_K_Current (dimensionless)";
		algebraic[52]  = "b_K1 in component Inward_Rectifier_K_Current (dimensionless)";
		algebraic[53]  = "K1_ss in component Inward_Rectifier_K_Current (dimensionless)";
		algebraic[54]  = "I_K1 in component Inward_Rectifier_K_Current (picoA_per_picoF)";
		constants[29]  = "G_K1 in component Inward_Rectifier_K_Current (milliS_per_microF)";
		algebraic[55]  = "I_ClCa_junc in component Ca_Activated_Cl_Current (picoA_per_picoF)";
		algebraic[56]  = "I_ClCa_sl in component Ca_Activated_Cl_Current (picoA_per_picoF)";
		states[16]  = "Ca_j in component Calcium_Concentrations (millimolar)";
		states[17]  = "Ca_sl in component Calcium_Concentrations (millimolar)";
		constants[101]  = "E_Cl in component Nerst_Potentials (millivolt)";
		constants[30]  = "G_ClCa in component Ca_Activated_Cl_Current (milliS_per_microF)";
		constants[31]  = "Kd_ClCa in component Ca_Activated_Cl_Current (millimolar)";
		constants[32]  = "G_Cl_B in component Background_Cl_Current (milliS_per_microF)";
		algebraic[7]  = "d_ss in component L_Type_Calcium_Current (dimensionless)";
		algebraic[21]  = "alpha_d in component L_Type_Calcium_Current (millisecond)";
		algebraic[28]  = "beta_d in component L_Type_Calcium_Current (dimensionless)";
		algebraic[35]  = "gamma_d in component L_Type_Calcium_Current (millisecond)";
		algebraic[40]  = "tau_d in component L_Type_Calcium_Current (millisecond)";
		algebraic[8]  = "f_ss in component L_Type_Calcium_Current (dimensionless)";
		algebraic[22]  = "alpha_f in component L_Type_Calcium_Current (millisecond)";
		algebraic[29]  = "beta_f in component L_Type_Calcium_Current (millisecond)";
		algebraic[36]  = "gamma_f in component L_Type_Calcium_Current (millisecond)";
		algebraic[41]  = "tau_f in component L_Type_Calcium_Current (millisecond)";
		algebraic[9]  = "f_2_ss in component L_Type_Calcium_Current (dimensionless)";
		algebraic[23]  = "alpha_f_2 in component L_Type_Calcium_Current (millisecond)";
		algebraic[30]  = "beta_f_2 in component L_Type_Calcium_Current (millisecond)";
		algebraic[37]  = "gamma_f_2 in component L_Type_Calcium_Current (millisecond)";
		algebraic[42]  = "tau_f_2 in component L_Type_Calcium_Current (millisecond)";
		states[18]  = "d in component L_Type_Calcium_Current (dimensionless)";
		states[19]  = "f in component L_Type_Calcium_Current (dimensionless)";
		states[20]  = "f_2 in component L_Type_Calcium_Current (dimensionless)";
		states[21]  = "f_Ca_B_j in component L_Type_Calcium_Current (dimensionless)";
		states[22]  = "f_Ca_B_sl in component L_Type_Calcium_Current (dimensionless)";
		constants[33]  = "K_i in component Potassium_Concentrations (millimolar)";
		constants[34]  = "Ca_o in component Calcium_Concentrations (millimolar)";
		algebraic[60]  = "Ibar_Ca_j in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[61]  = "Ibar_Ca_sl in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[62]  = "Ibar_K in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[63]  = "Ibar_Na_j in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[64]  = "Ibar_Na_sl in component L_Type_Calcium_Current (picoA_per_picoF)";
		constants[35]  = "p_Ca in component L_Type_Calcium_Current (litre_per_farad_millisecond)";
		constants[36]  = "p_Na in component L_Type_Calcium_Current (litre_per_farad_millisecond)";
		constants[37]  = "p_K in component L_Type_Calcium_Current (litre_per_farad_millisecond)";
		algebraic[65]  = "I_Ca_junc in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[66]  = "I_Ca_sl in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[67]  = "I_Ca in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[69]  = "I_Ca_Na_junc in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[70]  = "I_Ca_Na_sl in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[72]  = "I_Ca_Na in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[68]  = "I_Ca_K in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[74]  = "I_Ca_L in component L_Type_Calcium_Current (picoA_per_picoF)";
		algebraic[71]  = "Ka_junc in component Na_Ca_Exchanger_Current (dimensionless)";
		algebraic[73]  = "Ka_sl in component Na_Ca_Exchanger_Current (dimensionless)";
		constants[38]  = "Kd_act in component Na_Ca_Exchanger_Current (millimolar)";
		constants[39]  = "Km_Ca_i in component Na_Ca_Exchanger_Current (millimolar)";
		constants[40]  = "Km_Ca_o in component Na_Ca_Exchanger_Current (millimolar)";
		constants[41]  = "Km_Na_i in component Na_Ca_Exchanger_Current (millimolar)";
		constants[42]  = "Km_Na_o in component Na_Ca_Exchanger_Current (millimolar)";
		constants[43]  = "k_sat in component Na_Ca_Exchanger_Current (dimensionless)";
		constants[44]  = "nu in component Na_Ca_Exchanger_Current (dimensionless)";
		algebraic[75]  = "s1_junc in component Na_Ca_Exchanger_Current (millimolar4)";
		algebraic[77]  = "s2_junc in component Na_Ca_Exchanger_Current (millimolar4)";
		algebraic[79]  = "s3_junc in component Na_Ca_Exchanger_Current (millimolar4)";
		algebraic[76]  = "s1_sl in component Na_Ca_Exchanger_Current (millimolar4)";
		algebraic[78]  = "s2_sl in component Na_Ca_Exchanger_Current (millimolar4)";
		algebraic[80]  = "s3_sl in component Na_Ca_Exchanger_Current (millimolar4)";
		constants[45]  = "Ibar_NCX in component Na_Ca_Exchanger_Current (picoA_per_picoF)";
		algebraic[82]  = "I_ncx_sl in component Na_Ca_Exchanger_Current (picoA_per_picoF)";
		algebraic[81]  = "I_ncx_junc in component Na_Ca_Exchanger_Current (picoA_per_picoF)";
		algebraic[84]  = "I_ncx in component Na_Ca_Exchanger_Current (picoA_per_picoF)";
		constants[46]  = "Km_P_Ca in component Sarcolemmal_Ca_Pump_Current (millimolar)";
		constants[47]  = "Ibar_PMCA in component Sarcolemmal_Ca_Pump_Current (picoA_per_picoF)";
		algebraic[83]  = "I_pCa_junc in component Sarcolemmal_Ca_Pump_Current (picoA_per_picoF)";
		algebraic[85]  = "I_pCa_sl in component Sarcolemmal_Ca_Pump_Current (picoA_per_picoF)";
		algebraic[87]  = "I_pCa in component Sarcolemmal_Ca_Pump_Current (picoA_per_picoF)";
		algebraic[112]  = "E_Ca_sl in component Nerst_Potentials (millivolt)";
		algebraic[109]  = "E_Ca_junc in component Nerst_Potentials (millivolt)";
		constants[48]  = "G_Ca_B in component Background_Ca_Current (milliS_per_microF)";
		algebraic[113]  = "I_Ca_Bk_sl in component Background_Ca_Current (picoA_per_picoF)";
		algebraic[110]  = "I_Ca_Bk_junc in component Background_Ca_Current (picoA_per_picoF)";
		algebraic[115]  = "I_Ca_Bk in component Background_Ca_Current (picoA_per_picoF)";
		constants[49]  = "Max_SR in component SR_Fluxes (dimensionless)";
		constants[50]  = "Min_SR in component SR_Fluxes (dimensionless)";
		states[23]  = "Ca_SR in component Calcium_Concentrations (millimolar)";
		constants[51]  = "ec50_SR in component SR_Fluxes (millimolar)";
		algebraic[11]  = "k_Ca_SR in component SR_Fluxes (dimensionless)";
		constants[52]  = "ko_Ca in component SR_Fluxes (per_milliM2_per_millis)";
		algebraic[25]  = "ko_SR_Ca in component SR_Fluxes (per_milliM2_per_millis)";
		constants[53]  = "ki_Ca in component SR_Fluxes (per_milliM_per_millis)";
		algebraic[32]  = "ki_SR_Ca in component SR_Fluxes (per_milliM_per_millis)";
		constants[54]  = "ki_m in component SR_Fluxes (per_millis)";
		constants[55]  = "ko_m in component SR_Fluxes (per_millis)";
		constants[56]  = "ks in component SR_Fluxes (per_millis)";
		constants[57]  = "Km_f in component SR_Fluxes (millimolar)";
		constants[58]  = "Km_r in component SR_Fluxes (millimolar)";
		algebraic[86]  = "J_SR_Ca_rel in component SR_Fluxes (milliM_per_millis)";
		algebraic[89]  = "J_SR_leak in component SR_Fluxes (milliM_per_millis)";
		algebraic[88]  = "J_ser_Ca in component SR_Fluxes (milliM_per_millis)";
		algebraic[39]  = "RI in component SR_Fluxes (dimensionless)";
		states[24]  = "Ry_Rr in component SR_Fluxes (dimensionless)";
		states[25]  = "Ry_Ro in component SR_Fluxes (dimensionless)";
		states[26]  = "Ry_Ri in component SR_Fluxes (dimensionless)";
		states[27]  = "Ca_i in component Calcium_Concentrations (millimolar)";
		constants[59]  = "V_max_SR_CaP in component SR_Fluxes (milliM_per_millis)";
		constants[60]  = "hill_SR_CaP in component SR_Fluxes (dimensionless)";
		constants[61]  = "Mg_i in component Magnesium_Concentrations (millimolar)";
		states[28]  = "TnC_l in component Cytosolic_Ca_Buffers (millimolar)";
		states[29]  = "TnC_h_c in component Cytosolic_Ca_Buffers (millimolar)";
		states[30]  = "TnC_h_m in component Cytosolic_Ca_Buffers (millimolar)";
		states[31]  = "CaM in component Cytosolic_Ca_Buffers (millimolar)";
		states[32]  = "Myo_c in component Cytosolic_Ca_Buffers (millimolar)";
		states[33]  = "Myo_m in component Cytosolic_Ca_Buffers (millimolar)";
		states[34]  = "SRB in component Cytosolic_Ca_Buffers (millimolar)";
		constants[62]  = "k_off_TnC_l in component Cytosolic_Ca_Buffers (per_millis)";
		constants[63]  = "k_off_TnC_h_Ca in component Cytosolic_Ca_Buffers (per_millis)";
		constants[64]  = "k_off_TnC_h_Mg in component Cytosolic_Ca_Buffers (per_millis)";
		constants[65]  = "k_off_CaM in component Cytosolic_Ca_Buffers (per_millis)";
		constants[66]  = "k_off_myo_Ca in component Cytosolic_Ca_Buffers (per_millis)";
		constants[67]  = "k_off_myo_Mg in component Cytosolic_Ca_Buffers (per_millis)";
		constants[68]  = "k_off_SR in component Cytosolic_Ca_Buffers (per_millis)";
		constants[69]  = "k_on_TnC_l in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[70]  = "k_on_TnC_h_Ca in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[71]  = "k_on_TnC_h_Mg in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[72]  = "k_on_CaM in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[73]  = "k_on_myo_Ca in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[74]  = "k_on_myo_Mg in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[75]  = "k_on_SR in component Cytosolic_Ca_Buffers (per_milliM_per_millis)";
		constants[76]  = "B_max_TnC_low in component Cytosolic_Ca_Buffers (millimolar)";
		constants[77]  = "B_max_TnC_high in component Cytosolic_Ca_Buffers (millimolar)";
		constants[78]  = "B_max_CaM in component Cytosolic_Ca_Buffers (millimolar)";
		constants[79]  = "B_max_myosin in component Cytosolic_Ca_Buffers (millimolar)";
		constants[80]  = "B_max_SR in component Cytosolic_Ca_Buffers (millimolar)";
		algebraic[92]  = "J_Ca_B_cytosol in component Cytosolic_Ca_Buffers (milliM_per_millis)";
		constants[105]  = "B_max_SL_low_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
		constants[106]  = "B_max_SL_low_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
		constants[107]  = "B_max_SL_high_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
		constants[108]  = "B_max_SL_high_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
		constants[81]  = "k_off_sl_l in component Junctional_and_SL_Ca_Buffers (per_millis)";
		constants[82]  = "k_off_sl_h in component Junctional_and_SL_Ca_Buffers (per_millis)";
		constants[83]  = "k_on_sl_l in component Junctional_and_SL_Ca_Buffers (per_milliM_per_millis)";
		constants[84]  = "k_on_sl_h in component Junctional_and_SL_Ca_Buffers (per_milliM_per_millis)";
		states[35]  = "SLL_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
		states[36]  = "SLL_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
		states[37]  = "SLH_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
		states[38]  = "SLH_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
		algebraic[90]  = "J_Ca_B_junction in component Junctional_and_SL_Ca_Buffers (milliM_per_millis)";
		algebraic[91]  = "J_Ca_B_sl in component Junctional_and_SL_Ca_Buffers (milliM_per_millis)";
		constants[85]  = "B_max_Na_j in component Sodium_Concentrations (millimolar)";
		constants[86]  = "B_max_Na_sl in component Sodium_Concentrations (millimolar)";
		constants[87]  = "k_off_Na in component Sodium_Concentrations (per_millis)";
		constants[88]  = "k_on_Na in component Sodium_Concentrations (per_milliM_per_millis)";
		states[39]  = "Na_i in component Sodium_Concentrations (millimolar)";
		states[40]  = "Na_B_j in component Sodium_Concentrations (millimolar)";
		states[41]  = "Na_B_sl in component Sodium_Concentrations (millimolar)";
		constants[109]  = "B_max_csqn in component Calcium_Concentrations (millimolar)";
		states[42]  = "Csqn_b in component Calcium_Concentrations (millimolar)";
		constants[89]  = "k_off_csqn in component Calcium_Concentrations (per_millis)";
		constants[90]  = "k_on_csqn in component Calcium_Concentrations (per_milliM_per_millis)";
		constants[91]  = "Cl_i in component Chlorine_Concentrations (millimolar)";
		constants[92]  = "Cl_o in component Chlorine_Concentrations (millimolar)";
		constants[93]  = "p_Na_K in component Nerst_Potentials (dimensionless)";
		rates[0]  = "d/dt V in component membrane (millivolt)";
		rates[1]  = "d/dt Int_I_Na_tot in component membrane (picoA_ms_per_picoF)";
		rates[2]  = "d/dt Int_I_Cl_tot in component membrane (picoA_ms_per_picoF)";
		rates[3]  = "d/dt Int_I_Ca_tot in component membrane (picoA_ms_per_picoF)";
		rates[4]  = "d/dt Int_I_K_tot in component membrane (picoA_ms_per_picoF)";
		rates[5]  = "d/dt m in component Fast_Na_Current (dimensionless)";
		rates[6]  = "d/dt h in component Fast_Na_Current (dimensionless)";
		rates[7]  = "d/dt j in component Fast_Na_Current (dimensionless)";
		rates[10]  = "d/dt x_Kr in component Rapidly_Activating_K_Current (dimensionless)";
		rates[11]  = "d/dt x_Ks in component Slowly_Activating_K_Current (dimensionless)";
		rates[12]  = "d/dt x_to_s in component Transient_Outward_K_Current (dimensionless)";
		rates[13]  = "d/dt y_to_s in component Transient_Outward_K_Current (dimensionless)";
		rates[14]  = "d/dt x_to_f in component Transient_Outward_K_Current (dimensionless)";
		rates[15]  = "d/dt y_to_f in component Transient_Outward_K_Current (dimensionless)";
		rates[18]  = "d/dt d in component L_Type_Calcium_Current (dimensionless)";
		rates[19]  = "d/dt f in component L_Type_Calcium_Current (dimensionless)";
		rates[20]  = "d/dt f_2 in component L_Type_Calcium_Current (dimensionless)";
		rates[21]  = "d/dt f_Ca_B_j in component L_Type_Calcium_Current (dimensionless)";
		rates[22]  = "d/dt f_Ca_B_sl in component L_Type_Calcium_Current (dimensionless)";
		rates[24]  = "d/dt Ry_Rr in component SR_Fluxes (dimensionless)";
		rates[25]  = "d/dt Ry_Ro in component SR_Fluxes (dimensionless)";
		rates[26]  = "d/dt Ry_Ri in component SR_Fluxes (dimensionless)";
		rates[28]  = "d/dt TnC_l in component Cytosolic_Ca_Buffers (millimolar)";
		rates[29]  = "d/dt TnC_h_c in component Cytosolic_Ca_Buffers (millimolar)";
		rates[30]  = "d/dt TnC_h_m in component Cytosolic_Ca_Buffers (millimolar)";
		rates[31]  = "d/dt CaM in component Cytosolic_Ca_Buffers (millimolar)";
		rates[32]  = "d/dt Myo_c in component Cytosolic_Ca_Buffers (millimolar)";
		rates[33]  = "d/dt Myo_m in component Cytosolic_Ca_Buffers (millimolar)";
		rates[34]  = "d/dt SRB in component Cytosolic_Ca_Buffers (millimolar)";
		rates[35]  = "d/dt SLL_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
		rates[36]  = "d/dt SLL_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
		rates[37]  = "d/dt SLH_j in component Junctional_and_SL_Ca_Buffers (millimolar)";
		rates[38]  = "d/dt SLH_sl in component Junctional_and_SL_Ca_Buffers (millimolar)";
		rates[8]  = "d/dt Na_j in component Sodium_Concentrations (millimolar)";
		rates[40]  = "d/dt Na_B_j in component Sodium_Concentrations (millimolar)";
		rates[9]  = "d/dt Na_sl in component Sodium_Concentrations (millimolar)";
		rates[41]  = "d/dt Na_B_sl in component Sodium_Concentrations (millimolar)";
		rates[39]  = "d/dt Na_i in component Sodium_Concentrations (millimolar)";
		rates[42]  = "d/dt Csqn_b in component Calcium_Concentrations (millimolar)";
		rates[16]  = "d/dt Ca_j in component Calcium_Concentrations (millimolar)";
		rates[17]  = "d/dt Ca_sl in component Calcium_Concentrations (millimolar)";
		rates[27]  = "d/dt Ca_i in component Calcium_Concentrations (millimolar)";
		rates[23]  = "d/dt Ca_SR in component Calcium_Concentrations (millimolar)";
	}

	void initConsts(double* constants, double* states){
		states[0] = -8.413368e1;
		constants[0] = 8314;
		constants[1] = 310;
		constants[2] = 96485;
		constants[3] = 1.381e-10;
		constants[4] = 0;
		constants[5] = 40;
		constants[6] = 1000;
		constants[7] = 1;
		constants[8] = 0.11;
		constants[9] = 0.9;
		constants[10] = 100e-5;
		constants[11] = 10.25e-5;
		constants[12] = 8.2413e-13;
		constants[13] = 3.7243e-12;
		constants[14] = 1.8313e-14;
		constants[15] = 1.6386e-12;
		states[1] = 0;
		states[2] = 0;
		states[3] = 0;
		states[4] = 0;
		constants[16] = 18.86;
		states[5] = 2.163678e-3;
		states[6] = 7.13497e-1;
		states[7] = 7.128671e-1;
		constants[17] = 0.597e-3;
		constants[18] = 140;
		constants[19] = 0.99;
		constants[20] = 5.4;
		states[8] = 1.007931e1;
		states[9] = 1.00781e1;
		constants[21] = 1.5;
		constants[22] = 11;
		states[10] = 1.516232e-2;
		constants[23] = 0.035;
		states[11] = 3.549354e-3;
		constants[24] = 0.0035;
		constants[25] = 0.0035;
		constants[26] = 0.002;
		states[12] = 3.584727e-4;
		states[13] = 8.087629e-1;
		states[14] = 3.584625e-4;
		states[15] = 9.999976e-1;
		constants[27] = 0.0156;
		constants[28] = 0.1144;
		constants[29] = 0.57153;
		states[16] = 2.038197e-4;
		states[17] = 1.184305e-4;
		constants[30] = 0.054813;
		constants[31] = 100e-3;
		constants[32] = 9e-3;
		states[18] = 1.871177e-6;
		states[19] = 9.804391e-1;
		states[20] = 9.99401e-1;
		states[21] = 2.847118e-2;
		states[22] = 1.692189e-2;
		constants[33] = 138;
		constants[34] = 1.8;
		constants[35] = 1.9887e-4;
		constants[36] = 3.0375e-9;
		constants[37] = 5.4675e-8;
		constants[38] = 0.15e-3;
		constants[39] = 3.59e-3;
		constants[40] = 1.3;
		constants[41] = 12.29;
		constants[42] = 87.5;
		constants[43] = 0.32;
		constants[44] = 0.27;
		constants[45] = 4.5;
		constants[46] = 0.5e-3;
		constants[47] = 0.0673;
		constants[48] = 5.513e-4;
		constants[49] = 15;
		constants[50] = 1;
		states[23] = 6.093596e-1;
		constants[51] = 0.45;
		constants[52] = 10;
		constants[53] = 0.5;
		constants[54] = 0.005;
		constants[55] = 0.06;
		constants[56] = 25;
		constants[57] = 0.246e-3;
		constants[58] = 1.7;
		states[24] = 8.886338e-1;
		states[25] = 1.126209e-6;
		states[26] = 1.411382e-7;
		states[27] = 9.658067e-5;
		constants[59] = 5.3114e-3;
		constants[60] = 1.787;
		constants[61] = 1;
		states[28] = 9.757237e-3;
		states[29] = 1.225914e-1;
		states[30] = 8.12201e-3;
		states[31] = 3.267494e-4;
		states[32] = 2.520383e-3;
		states[33] = 1.369529e-1;
		states[34] = 2.373753e-3;
		constants[62] = 19.6e-3;
		constants[63] = 0.032e-3;
		constants[64] = 3.33e-3;
		constants[65] = 238e-3;
		constants[66] = 0.46e-3;
		constants[67] = 0.057e-3;
		constants[68] = 60e-3;
		constants[69] = 32.7;
		constants[70] = 2.37;
		constants[71] = 3e-3;
		constants[72] = 34;
		constants[73] = 13.8;
		constants[74] = 0.0157;
		constants[75] = 100;
		constants[76] = 70e-3;
		constants[77] = 140e-3;
		constants[78] = 24e-3;
		constants[79] = 140e-3;
		constants[80] = 17.1e-3;
		constants[81] = 1.3;
		constants[82] = 30e-3;
		constants[83] = 100;
		constants[84] = 100;
		states[35] = 8.563314e-3;
		states[36] = 1.097424e-2;
		states[37] = 8.053908e-2;
		states[38] = 1.235381e-1;
		constants[85] = 7.561;
		constants[86] = 1.65;
		constants[87] = 1e-3;
		constants[88] = 0.1e-3;
		states[39] = 1.007825e1;
		states[40] = 3.796195e0;
		states[41] = 8.283308e-1;
		states[42] = 1.258048e0;
		constants[89] = 65;
		constants[90] = 100;
		constants[91] = 15;
		constants[92] = 150;
		constants[93] = 0.01833;
		constants[94] = constants[2]/( constants[0]*constants[1]);
		constants[95] = 1.00000 - constants[8];
		constants[96] = 1.00000 - constants[9];
		constants[97] =   3.14159265358979*pow(constants[11], 2.00000)*constants[10];
		constants[98] =  (exp( constants[18]*0.0148588) - 1.00000)*0.142857;
		constants[99] =  0.650000*constants[97];
		constants[100] =  (1.00000/constants[94])*log(constants[20]/constants[33]);
		constants[101] =  (1.00000/constants[94])*log(constants[91]/constants[92]);
		constants[102] =  0.0200000*constants[97];
		constants[103] =  0.0350000*constants[97];
		constants[104] =  0.000539000*constants[97];
		constants[105] = ( 0.000460000*constants[99])/constants[104];
		constants[106] = ( 0.0374000*constants[99])/constants[102];
		constants[107] = ( 0.000165000*constants[99])/constants[104];
		constants[108] = ( 0.0134000*constants[99])/constants[102];
		constants[109] = ( 0.140000*constants[99])/constants[103];
	}

	void computeRates(double VoI, double* constants, double* rates, double* states, double* algebraic){
		rates[21] =  1.70000*states[16]*(1.00000 - states[21]) -  0.0119000*states[21];
		rates[22] =  1.70000*states[17]*(1.00000 - states[22]) -  0.0119000*states[22];
		rates[39] =  (constants[15]/constants[99])*(states[9] - states[39]);
		algebraic[0] = 1.00000/pow(1.00000+exp( - (56.8600+states[0])*0.110742), 2.00000);
		algebraic[12] =  0.129200*exp(- pow( (states[0]+45.7900)*0.0643501, 2.00000))+ 0.0648700*exp(- pow( (states[0] - 4.82300)*0.0195618, 2.00000));
		rates[5] = (algebraic[0] - states[5])/algebraic[12];
		algebraic[3] = 1.00000/(1.00000+exp( - (states[0]+10.0000)*0.200000));
		algebraic[15] = 3300.00/(1.29457+exp( (- 22.0000 - states[0])*0.111111)+exp( (states[0]+11.0000)*0.111111))+230.000/(1.00000+exp( (states[0]+40.0000)*0.0500000));
		rates[10] = (algebraic[3] - states[10])/algebraic[15];
		algebraic[4] = 1.00000/(1.00000+exp( - (states[0]+3.80000)*0.0701754));
		algebraic[16] =  (1.00000+exp( - (states[0]+2.43600)*0.0708215))*0.00101000;
		rates[11] =  (algebraic[4] - states[11])*algebraic[16];
		algebraic[5] = 1.00000/(1.00000+exp( - (states[0] - 19.0000)*0.0769231));
		algebraic[17] = 9.00000/(1.00000+exp( (states[0]+3.00000)*0.0666667))+0.500000;
		rates[12] = (algebraic[5] - states[12])/algebraic[17];
		algebraic[6] = 1.00000/(1.00000+exp( (states[0]+19.5000)*0.200000));
		algebraic[18] = 800.000/(1.00000+exp( (states[0]+60.0000)*0.100000))+30.0000;
		rates[13] = (algebraic[6] - states[13])/algebraic[18];
		algebraic[19] =  8.50000*exp(- pow( (states[0]+45.0000)*0.0200000, 2.00000))+0.500000;
		rates[14] = (algebraic[5] - states[14])/algebraic[19];
		algebraic[20] =  85.0000*exp( - pow(states[0]+40.0000, 2.00000)*0.00454545)+7.00000;
		rates[15] = (algebraic[6] - states[15])/algebraic[20];
		algebraic[11] = constants[49] - (constants[49] - constants[50])/(1.00000+pow(constants[51]/states[23], 2.50000));
		algebraic[25] = constants[52]/algebraic[11];
		algebraic[32] =  constants[53]*algebraic[11];
		rates[25] = ( algebraic[25]*pow(states[16], 2.00000)*states[24] -  constants[55]*states[25]) - ( algebraic[32]*states[16]*states[25] -  constants[54]*states[26]);
		algebraic[1] = (states[0]>=- 40.0000 ? 0.00000 :  0.0570000*exp( - (states[0]+80.0000)*0.147059));
		algebraic[13] = (states[0]>=- 40.0000 ? 5.92310/(1.00000+exp( - (states[0]+10.6600)*0.0900901)) :  2.70000*exp( 0.0790000*states[0])+ 310000.*exp( 0.348500*states[0]));
		algebraic[26] = algebraic[1]+algebraic[13];
		algebraic[33] = 1.00000/pow(1.00000+exp( (states[0]+71.5500)*0.134590), 2.00000);
		rates[6] =  (algebraic[33] - states[6])*algebraic[26];
		algebraic[2] = (states[0]>=- 40.0000 ? 0.00000 : ( ( - 25428.0*exp( 0.244400*states[0]) -  6.94800e-06*exp( - 0.0439100*states[0]))*(states[0]+37.7800))/(1.00000+exp( 0.311000*(states[0]+79.2300))));
		algebraic[14] = (states[0]>=- 40.0000 ? ( 0.600000*exp( 0.0570000*states[0]))/(1.00000+exp( - 0.100000*(states[0]+32.0000))) : ( 0.0242400*exp( - 0.0105200*states[0]))/(1.00000+exp( - 0.137800*(states[0]+40.1400))));
		algebraic[27] = algebraic[2]+algebraic[14];
		algebraic[34] = 1.00000/pow(1.00000+exp( (states[0]+71.5500)*0.134590), 2.00000);
		rates[7] =  (algebraic[34] - states[7])*algebraic[27];
		algebraic[39] = ((1.00000 - states[24]) - states[25]) - states[26];
		rates[24] = ( constants[54]*algebraic[39] -  algebraic[32]*states[16]*states[24]) - ( algebraic[25]*pow(states[16], 2.00000)*states[24] -  constants[55]*states[25]);
		rates[26] = ( algebraic[32]*states[16]*states[25] -  constants[54]*states[26]) - ( constants[55]*states[26] -  algebraic[25]*pow(states[16], 2.00000)*algebraic[39]);
		algebraic[7] = 1.00000/(1.00000+exp( - (states[0]+5.00000)*0.166667));
		algebraic[21] = 1.40000/(1.00000+exp( (- 35.0000 - states[0])*0.0769231))+0.250000;
		algebraic[28] = 1.40000/(1.00000+exp( (states[0]+5.00000)*0.200000));
		algebraic[35] = 1.00000/(1.00000+exp( (50.0000 - states[0])*0.0500000));
		algebraic[40] =  algebraic[21]*algebraic[28]+algebraic[35];
		rates[18] = (algebraic[7] - states[18])/algebraic[40];
		algebraic[8] = 1.00000/(1.00000+exp( (states[0]+20.0000)*0.142857));
		algebraic[22] =  1102.50*exp(- pow( (states[0]+27.0000)*0.0666667, 2.00000));
		algebraic[29] = 200.000/(1.00000+exp( (13.0000 - states[0])*0.100000));
		algebraic[36] = 180.000/(1.00000+exp( (states[0]+30.0000)*0.100000))+20.0000;
		algebraic[41] = algebraic[22]+algebraic[29]+algebraic[36];
		rates[19] = (algebraic[8] - states[19])/algebraic[41];
		algebraic[9] = 0.670000/(1.00000+exp( (states[0]+35.0000)*0.142857))+0.330000;
		algebraic[23] =  300.000*exp( - pow(states[0]+25.0000, 2.00000)*0.00588235);
		algebraic[30] = 31.0000/(1.00000+exp( (25.0000 - states[0])*0.100000));
		algebraic[37] = 16.0000/(1.00000+exp( (states[0]+30.0000)*0.100000));
		algebraic[42] = algebraic[23]+algebraic[30]+algebraic[37];
		rates[20] = (algebraic[9] - states[20])/algebraic[42];
		algebraic[55] =  (( constants[8]*constants[30])/(1.00000+constants[31]/states[16]))*(states[0] - constants[101]);
		algebraic[56] =  (( constants[95]*constants[30])/(1.00000+constants[31]/states[17]))*(states[0] - constants[101]);
		algebraic[57] = algebraic[55]+algebraic[56];
		algebraic[58] =  constants[32]*(states[0] - constants[101]);
		algebraic[59] = algebraic[57]+algebraic[58];
		rates[2] = algebraic[59];
		rates[28] =  constants[69]*states[27]*(constants[76] - states[28]) -  constants[62]*states[28];
		rates[35] =  constants[83]*states[16]*(constants[105] - states[35]) -  constants[81]*states[35];
		rates[29] =  constants[70]*states[27]*((constants[77] - states[29]) - states[30]) -  constants[63]*states[29];
		rates[42] =  constants[90]*states[23]*(constants[109] - states[42]) -  constants[89]*states[42];
		rates[36] =  constants[83]*states[17]*(constants[106] - states[36]) -  constants[81]*states[36];
		rates[30] =  constants[71]*constants[61]*((constants[77] - states[29]) - states[30]) -  constants[64]*states[30];
		algebraic[86] =  constants[56]*states[25]*(states[23] - states[16]);
		algebraic[89] =  5.34800e-06*(states[23] - states[16]);
		algebraic[88] = ( constants[59]*(pow(states[27]/constants[57], constants[60]) - pow(states[23]/constants[58], constants[60])))/(1.00000+pow(states[27]/constants[57], constants[60])+pow(states[23]/constants[58], constants[60]));
		rates[23] = (algebraic[88] - (( algebraic[89]*constants[99])/constants[103]+algebraic[86])) - rates[42];
		rates[37] =  constants[84]*states[16]*(constants[107] - states[37]) -  constants[82]*states[37];
		rates[31] =  constants[72]*states[27]*(constants[78] - states[31]) -  constants[65]*states[31];
		rates[38] =  constants[84]*states[17]*(constants[108] - states[38]) -  constants[82]*states[38];
		rates[32] =  constants[73]*states[27]*((constants[79] - states[32]) - states[33]) -  constants[66]*states[32];
		rates[33] =  constants[74]*constants[61]*((constants[79] - states[32]) - states[33]) -  constants[67]*states[33];
		rates[34] =  constants[75]*states[27]*(constants[80] - states[34]) -  constants[68]*states[34];
		rates[40] =  constants[88]*states[8]*(constants[85] - states[40]) -  constants[87]*states[40];
		rates[41] =  constants[88]*states[9]*(constants[86] - states[41]) -  constants[87]*states[41];
		algebraic[92] = rates[28]+rates[29]+rates[30]+rates[31]+rates[32]+rates[33]+rates[34];
		rates[27] = (( - algebraic[88]*constants[103])/constants[99] - algebraic[92])+ (constants[13]/constants[99])*(states[17] - states[27]);
		algebraic[93] =  (1.00000/constants[94])*log(constants[18]/states[8]);
		algebraic[94] =  constants[8]*constants[16]*pow(states[5], 3.00000)*states[6]*states[7]*(states[0] - algebraic[93]);
		algebraic[95] =  constants[8]*constants[17]*(states[0] - algebraic[93]);
		algebraic[24] = 1.00000/(1.00000+ 0.124500*exp( - 0.100000*states[0]*constants[94])+ 0.0365000*constants[98]*exp( - states[0]*constants[94]));
		algebraic[31] = ( constants[8]*constants[19]*algebraic[24]*constants[20])/( (1.00000+pow(constants[22]/states[8], 4.00000))*(constants[20]+constants[21]));
		algebraic[63] = ( constants[36]*states[0]*constants[2]*constants[94]*( states[8]*exp( states[0]*constants[94]) - constants[18]))/(exp( states[0]*constants[94]) - 1.00000);
		algebraic[69] =  constants[9]*algebraic[63]*states[18]*states[19]*states[20]*(1.00000 - states[21]);
		algebraic[71] = 1.00000/(1.00000+pow(constants[38]/states[16], 2.00000));
		algebraic[75] =  exp( constants[44]*states[0]*constants[94])*pow(states[8], 3.00000)*constants[34];
		algebraic[77] =  exp( (constants[44] - 1.00000)*states[0]*constants[94])*pow(constants[18], 3.00000)*states[16];
		algebraic[79] =  constants[39]*pow(constants[18], 3.00000)*(1.00000+pow(states[8]/constants[41], 3.00000))+ pow(constants[42], 3.00000)*states[16]*(1.00000+states[16]/constants[39])+ constants[40]*pow(states[8], 3.00000)+ pow(states[8], 3.00000)*constants[34]+ pow(constants[18], 3.00000)*states[16];
		algebraic[81] = ( constants[8]*constants[45]*algebraic[71]*(algebraic[75] - algebraic[77]))/( algebraic[79]*(1.00000+ constants[43]*exp( (constants[44] - 1.00000)*states[0]*constants[94])));
		algebraic[96] = algebraic[94]+algebraic[95]+ 3.00000*algebraic[81]+ 3.00000*algebraic[31]+algebraic[69];
		rates[8] = (( - algebraic[96]*constants[3])/( constants[104]*constants[2])+ (constants[14]/constants[104])*(states[9] - states[8])) - rates[40];
		algebraic[97] =  (1.00000/constants[94])*log(constants[18]/states[9]);
		algebraic[98] =  constants[95]*constants[16]*pow(states[5], 3.00000)*states[6]*states[7]*(states[0] - algebraic[97]);
		algebraic[100] =  constants[95]*constants[17]*(states[0] - algebraic[97]);
		algebraic[38] = ( constants[95]*constants[19]*algebraic[24]*constants[20])/( (1.00000+pow(constants[22]/states[9], 4.00000))*(constants[20]+constants[21]));
		algebraic[64] = ( constants[36]*states[0]*constants[2]*constants[94]*( states[9]*exp( states[0]*constants[94]) - constants[18]))/(exp( states[0]*constants[94]) - 1.00000);
		algebraic[70] =  constants[96]*algebraic[64]*states[18]*states[19]*states[20]*(1.00000 - states[22]);
		algebraic[73] = 1.00000/(1.00000+pow(constants[38]/states[17], 2.00000));
		algebraic[76] =  exp( constants[44]*states[0]*constants[94])*pow(states[9], 3.00000)*constants[34];
		algebraic[78] =  exp( (constants[44] - 1.00000)*states[0]*constants[94])*pow(constants[18], 3.00000)*states[17];
		algebraic[80] =  constants[39]*pow(constants[18], 3.00000)*(1.00000+pow(states[9]/constants[41], 3.00000))+ pow(constants[42], 3.00000)*states[17]*(1.00000+states[17]/constants[39])+ constants[40]*pow(states[9], 3.00000)+ pow(states[9], 3.00000)*constants[34]+ pow(constants[18], 3.00000)*states[17];
		algebraic[82] = ( constants[95]*constants[45]*algebraic[73]*(algebraic[76] - algebraic[78]))/( algebraic[80]*(1.00000+ constants[43]*exp( (constants[44] - 1.00000)*states[0]*constants[94])));
		algebraic[102] = algebraic[98]+algebraic[100]+ 3.00000*algebraic[82]+ 3.00000*algebraic[38]+algebraic[70];
		rates[9] = (( - algebraic[102]*constants[3])/( constants[102]*constants[2])+ (constants[14]/constants[102])*(states[8] - states[9])+ (constants[15]/constants[102])*(states[39] - states[9])) - rates[41];
		algebraic[103] = algebraic[96]+algebraic[102];
		rates[1] = algebraic[103];
		algebraic[43] = algebraic[31]+algebraic[38];
		algebraic[44] = 1.00000/(1.00000+exp( (states[0]+74.0000)*0.0416667));
		algebraic[45] =  constants[23]* pow(( constants[20]*0.185185), 1.0 / 2)*states[10]*algebraic[44]*(states[0] - constants[100]);
		algebraic[104] =  (1.00000/constants[94])*log((constants[20]+ constants[93]*constants[18])/(constants[33]+ constants[93]*states[39]));
		algebraic[105] =  constants[8]*constants[24]*pow(states[11], 2.00000)*(states[0] - algebraic[104]);
		algebraic[106] =  constants[95]*constants[25]*pow(states[11], 2.00000)*(states[0] - algebraic[104]);
		algebraic[107] = algebraic[105]+algebraic[106];
		algebraic[46] = 1.00000/(1.00000+exp(7.48800 -  states[0]*0.167224));
		algebraic[47] =  constants[26]*algebraic[46]*(states[0] - constants[100]);
		algebraic[48] =  constants[27]*states[12]*states[13]*(states[0] - constants[100]);
		algebraic[49] =  constants[28]*states[14]*states[15]*(states[0] - constants[100]);
		algebraic[50] = algebraic[48]+algebraic[49];
		algebraic[51] = 4.09380/(1.00000+exp( 0.121650*((states[0] - constants[100]) - 49.9344)));
		algebraic[52] = ( 15.7197*exp( 0.0673900*((states[0] - constants[100]) - 3.25710))+exp( 0.0617500*((states[0] - constants[100]) - 594.310)))/(1.00000+exp( - 0.162850*((states[0] - constants[100])+14.2067)));
		algebraic[53] = algebraic[51]/(algebraic[51]+algebraic[52]);
		algebraic[54] =  constants[29]* pow(( constants[20]*0.185185), 1.0 / 2)*algebraic[53]*(states[0] - constants[100]);
		algebraic[62] = ( constants[37]*states[0]*constants[2]*constants[94]*( constants[33]*exp( states[0]*constants[94]) - constants[20]))/(exp( states[0]*constants[94]) - 1.00000);
		algebraic[68] =  algebraic[62]*states[18]*states[19]*states[20]*( constants[9]*(1.00000 - states[21])+ constants[96]*(1.00000 - states[22]));
		algebraic[108] = ((algebraic[50]+algebraic[45]+algebraic[107]+algebraic[54]) -  2.00000*algebraic[43])+algebraic[68]+algebraic[47];
		rates[4] = algebraic[108];
		algebraic[60] = ( constants[35]*states[0]*constants[2]*constants[94]*( states[16]*exp( 2.00000*states[0]*constants[94]) - constants[34]))/(exp( 2.00000*states[0]*constants[94]) - 1.00000);
		algebraic[65] =  constants[9]*algebraic[60]*states[18]*states[19]*states[20]*(1.00000 - states[21]);
		algebraic[83] = ( constants[8]*constants[47]*pow(states[16], 1.60000))/(pow(constants[46], 1.60000)+pow(states[16], 1.60000));
		algebraic[109] =  (1.00000/( 2.00000*constants[94]))*log(constants[34]/states[16]);
		algebraic[110] =  constants[8]*constants[48]*(states[0] - algebraic[109]);
		algebraic[111] = (algebraic[65]+algebraic[110]+algebraic[83]) -  2.00000*algebraic[81];
		algebraic[90] = rates[35]+rates[37];
		rates[16] = ((( - algebraic[111]*constants[3])/( constants[104]*2.00000*constants[2])+ (constants[12]/constants[104])*(states[17] - states[16])) - algebraic[90])+( algebraic[86]*constants[103])/constants[104]+( algebraic[89]*constants[99])/constants[104];
		algebraic[61] = ( constants[35]*states[0]*constants[2]*constants[94]*( states[17]*exp( 2.00000*states[0]*constants[94]) - constants[34]))/(exp( 2.00000*states[0]*constants[94]) - 1.00000);
		algebraic[66] =  constants[96]*algebraic[61]*states[18]*states[19]*states[20]*(1.00000 - states[22]);
		algebraic[85] = ( constants[95]*constants[47]*pow(states[17], 1.60000))/(pow(constants[46], 1.60000)+pow(states[17], 1.60000));
		algebraic[112] =  (1.00000/( 2.00000*constants[94]))*log(constants[34]/states[17]);
		algebraic[113] =  constants[95]*constants[48]*(states[0] - algebraic[112]);
		algebraic[114] = (algebraic[66]+algebraic[113]+algebraic[85]) -  2.00000*algebraic[82];
		algebraic[91] = rates[36]+rates[38];
		rates[17] = (( - algebraic[114]*constants[3])/( constants[102]*2.00000*constants[2])+ (constants[12]/constants[102])*(states[16] - states[17])+ (constants[13]/constants[102])*(states[27] - states[17])) - algebraic[91];
		algebraic[116] = algebraic[111]+algebraic[114];
		rates[3] = algebraic[116];
		algebraic[117] = algebraic[103]+algebraic[59]+algebraic[116]+algebraic[108];
		algebraic[10] = ((VoI - constants[4]) -  floor((VoI - constants[4])/constants[6])*constants[6]<=constants[7] ? constants[5] : 0.00000);
		rates[0] = - (algebraic[117] - algebraic[10]);
	}

	void computeVariables(double VoI, double* constants, double* rates, double* states, double* algebraic){
		algebraic[0] = 1.00000/pow(1.00000+exp( - (56.8600+states[0])*0.110742), 2.00000);
		algebraic[12] =  0.129200*exp(- pow( (states[0]+45.7900)*0.0643501, 2.00000))+ 0.0648700*exp(- pow( (states[0] - 4.82300)*0.0195618, 2.00000));
		algebraic[3] = 1.00000/(1.00000+exp( - (states[0]+10.0000)*0.200000));
		algebraic[15] = 3300.00/(1.29457+exp( (- 22.0000 - states[0])*0.111111)+exp( (states[0]+11.0000)*0.111111))+230.000/(1.00000+exp( (states[0]+40.0000)*0.0500000));
		algebraic[4] = 1.00000/(1.00000+exp( - (states[0]+3.80000)*0.0701754));
		algebraic[16] =  (1.00000+exp( - (states[0]+2.43600)*0.0708215))*0.00101000;
		algebraic[5] = 1.00000/(1.00000+exp( - (states[0] - 19.0000)*0.0769231));
		algebraic[17] = 9.00000/(1.00000+exp( (states[0]+3.00000)*0.0666667))+0.500000;
		algebraic[6] = 1.00000/(1.00000+exp( (states[0]+19.5000)*0.200000));
		algebraic[18] = 800.000/(1.00000+exp( (states[0]+60.0000)*0.100000))+30.0000;
		algebraic[19] =  8.50000*exp(- pow( (states[0]+45.0000)*0.0200000, 2.00000))+0.500000;
		algebraic[20] =  85.0000*exp( - pow(states[0]+40.0000, 2.00000)*0.00454545)+7.00000;
		algebraic[11] = constants[49] - (constants[49] - constants[50])/(1.00000+pow(constants[51]/states[23], 2.50000));
		algebraic[25] = constants[52]/algebraic[11];
		algebraic[32] =  constants[53]*algebraic[11];
		algebraic[1] = (states[0]>=- 40.0000 ? 0.00000 :  0.0570000*exp( - (states[0]+80.0000)*0.147059));
		algebraic[13] = (states[0]>=- 40.0000 ? 5.92310/(1.00000+exp( - (states[0]+10.6600)*0.0900901)) :  2.70000*exp( 0.0790000*states[0])+ 310000.*exp( 0.348500*states[0]));
		algebraic[26] = algebraic[1]+algebraic[13];
		algebraic[33] = 1.00000/pow(1.00000+exp( (states[0]+71.5500)*0.134590), 2.00000);
		algebraic[2] = (states[0]>=- 40.0000 ? 0.00000 : ( ( - 25428.0*exp( 0.244400*states[0]) -  6.94800e-06*exp( - 0.0439100*states[0]))*(states[0]+37.7800))/(1.00000+exp( 0.311000*(states[0]+79.2300))));
		algebraic[14] = (states[0]>=- 40.0000 ? ( 0.600000*exp( 0.0570000*states[0]))/(1.00000+exp( - 0.100000*(states[0]+32.0000))) : ( 0.0242400*exp( - 0.0105200*states[0]))/(1.00000+exp( - 0.137800*(states[0]+40.1400))));
		algebraic[27] = algebraic[2]+algebraic[14];
		algebraic[34] = 1.00000/pow(1.00000+exp( (states[0]+71.5500)*0.134590), 2.00000);
		algebraic[39] = ((1.00000 - states[24]) - states[25]) - states[26];
		algebraic[7] = 1.00000/(1.00000+exp( - (states[0]+5.00000)*0.166667));
		algebraic[21] = 1.40000/(1.00000+exp( (- 35.0000 - states[0])*0.0769231))+0.250000;
		algebraic[28] = 1.40000/(1.00000+exp( (states[0]+5.00000)*0.200000));
		algebraic[35] = 1.00000/(1.00000+exp( (50.0000 - states[0])*0.0500000));
		algebraic[40] =  algebraic[21]*algebraic[28]+algebraic[35];
		algebraic[8] = 1.00000/(1.00000+exp( (states[0]+20.0000)*0.142857));
		algebraic[22] =  1102.50*exp(- pow( (states[0]+27.0000)*0.0666667, 2.00000));
		algebraic[29] = 200.000/(1.00000+exp( (13.0000 - states[0])*0.100000));
		algebraic[36] = 180.000/(1.00000+exp( (states[0]+30.0000)*0.100000))+20.0000;
		algebraic[41] = algebraic[22]+algebraic[29]+algebraic[36];
		algebraic[9] = 0.670000/(1.00000+exp( (states[0]+35.0000)*0.142857))+0.330000;
		algebraic[23] =  300.000*exp( - pow(states[0]+25.0000, 2.00000)*0.00588235);
		algebraic[30] = 31.0000/(1.00000+exp( (25.0000 - states[0])*0.100000));
		algebraic[37] = 16.0000/(1.00000+exp( (states[0]+30.0000)*0.100000));
		algebraic[42] = algebraic[23]+algebraic[30]+algebraic[37];
		algebraic[55] =  (( constants[8]*constants[30])/(1.00000+constants[31]/states[16]))*(states[0] - constants[101]);
		algebraic[56] =  (( constants[95]*constants[30])/(1.00000+constants[31]/states[17]))*(states[0] - constants[101]);
		algebraic[57] = algebraic[55]+algebraic[56];
		algebraic[58] =  constants[32]*(states[0] - constants[101]);
		algebraic[59] = algebraic[57]+algebraic[58];
		algebraic[86] =  constants[56]*states[25]*(states[23] - states[16]);
		algebraic[89] =  5.34800e-06*(states[23] - states[16]);
		algebraic[88] = ( constants[59]*(pow(states[27]/constants[57], constants[60]) - pow(states[23]/constants[58], constants[60])))/(1.00000+pow(states[27]/constants[57], constants[60])+pow(states[23]/constants[58], constants[60]));
		algebraic[92] = rates[28]+rates[29]+rates[30]+rates[31]+rates[32]+rates[33]+rates[34];
		algebraic[93] =  (1.00000/constants[94])*log(constants[18]/states[8]);
		algebraic[94] =  constants[8]*constants[16]*pow(states[5], 3.00000)*states[6]*states[7]*(states[0] - algebraic[93]);
		algebraic[95] =  constants[8]*constants[17]*(states[0] - algebraic[93]);
		algebraic[24] = 1.00000/(1.00000+ 0.124500*exp( - 0.100000*states[0]*constants[94])+ 0.0365000*constants[98]*exp( - states[0]*constants[94]));
		algebraic[31] = ( constants[8]*constants[19]*algebraic[24]*constants[20])/( (1.00000+pow(constants[22]/states[8], 4.00000))*(constants[20]+constants[21]));
		algebraic[63] = ( constants[36]*states[0]*constants[2]*constants[94]*( states[8]*exp( states[0]*constants[94]) - constants[18]))/(exp( states[0]*constants[94]) - 1.00000);
		algebraic[69] =  constants[9]*algebraic[63]*states[18]*states[19]*states[20]*(1.00000 - states[21]);
		algebraic[71] = 1.00000/(1.00000+pow(constants[38]/states[16], 2.00000));
		algebraic[75] =  exp( constants[44]*states[0]*constants[94])*pow(states[8], 3.00000)*constants[34];
		algebraic[77] =  exp( (constants[44] - 1.00000)*states[0]*constants[94])*pow(constants[18], 3.00000)*states[16];
		algebraic[79] =  constants[39]*pow(constants[18], 3.00000)*(1.00000+pow(states[8]/constants[41], 3.00000))+ pow(constants[42], 3.00000)*states[16]*(1.00000+states[16]/constants[39])+ constants[40]*pow(states[8], 3.00000)+ pow(states[8], 3.00000)*constants[34]+ pow(constants[18], 3.00000)*states[16];
		algebraic[81] = ( constants[8]*constants[45]*algebraic[71]*(algebraic[75] - algebraic[77]))/( algebraic[79]*(1.00000+ constants[43]*exp( (constants[44] - 1.00000)*states[0]*constants[94])));
		algebraic[96] = algebraic[94]+algebraic[95]+ 3.00000*algebraic[81]+ 3.00000*algebraic[31]+algebraic[69];
		algebraic[97] =  (1.00000/constants[94])*log(constants[18]/states[9]);
		algebraic[98] =  constants[95]*constants[16]*pow(states[5], 3.00000)*states[6]*states[7]*(states[0] - algebraic[97]);
		algebraic[100] =  constants[95]*constants[17]*(states[0] - algebraic[97]);
		algebraic[38] = ( constants[95]*constants[19]*algebraic[24]*constants[20])/( (1.00000+pow(constants[22]/states[9], 4.00000))*(constants[20]+constants[21]));
		algebraic[64] = ( constants[36]*states[0]*constants[2]*constants[94]*( states[9]*exp( states[0]*constants[94]) - constants[18]))/(exp( states[0]*constants[94]) - 1.00000);
		algebraic[70] =  constants[96]*algebraic[64]*states[18]*states[19]*states[20]*(1.00000 - states[22]);
		algebraic[73] = 1.00000/(1.00000+pow(constants[38]/states[17], 2.00000));
		algebraic[76] =  exp( constants[44]*states[0]*constants[94])*pow(states[9], 3.00000)*constants[34];
		algebraic[78] =  exp( (constants[44] - 1.00000)*states[0]*constants[94])*pow(constants[18], 3.00000)*states[17];
		algebraic[80] =  constants[39]*pow(constants[18], 3.00000)*(1.00000+pow(states[9]/constants[41], 3.00000))+ pow(constants[42], 3.00000)*states[17]*(1.00000+states[17]/constants[39])+ constants[40]*pow(states[9], 3.00000)+ pow(states[9], 3.00000)*constants[34]+ pow(constants[18], 3.00000)*states[17];
		algebraic[82] = ( constants[95]*constants[45]*algebraic[73]*(algebraic[76] - algebraic[78]))/( algebraic[80]*(1.00000+ constants[43]*exp( (constants[44] - 1.00000)*states[0]*constants[94])));
		algebraic[102] = algebraic[98]+algebraic[100]+ 3.00000*algebraic[82]+ 3.00000*algebraic[38]+algebraic[70];
		algebraic[103] = algebraic[96]+algebraic[102];
		algebraic[43] = algebraic[31]+algebraic[38];
		algebraic[44] = 1.00000/(1.00000+exp( (states[0]+74.0000)*0.0416667));
		algebraic[45] =  constants[23]* pow(( constants[20]*0.185185), 1.0 / 2)*states[10]*algebraic[44]*(states[0] - constants[100]);
		algebraic[104] =  (1.00000/constants[94])*log((constants[20]+ constants[93]*constants[18])/(constants[33]+ constants[93]*states[39]));
		algebraic[105] =  constants[8]*constants[24]*pow(states[11], 2.00000)*(states[0] - algebraic[104]);
		algebraic[106] =  constants[95]*constants[25]*pow(states[11], 2.00000)*(states[0] - algebraic[104]);
		algebraic[107] = algebraic[105]+algebraic[106];
		algebraic[46] = 1.00000/(1.00000+exp(7.48800 -  states[0]*0.167224));
		algebraic[47] =  constants[26]*algebraic[46]*(states[0] - constants[100]);
		algebraic[48] =  constants[27]*states[12]*states[13]*(states[0] - constants[100]);
		algebraic[49] =  constants[28]*states[14]*states[15]*(states[0] - constants[100]);
		algebraic[50] = algebraic[48]+algebraic[49];
		algebraic[51] = 4.09380/(1.00000+exp( 0.121650*((states[0] - constants[100]) - 49.9344)));
		algebraic[52] = ( 15.7197*exp( 0.0673900*((states[0] - constants[100]) - 3.25710))+exp( 0.0617500*((states[0] - constants[100]) - 594.310)))/(1.00000+exp( - 0.162850*((states[0] - constants[100])+14.2067)));
		algebraic[53] = algebraic[51]/(algebraic[51]+algebraic[52]);
		algebraic[54] =  constants[29]* pow(( constants[20]*0.185185), 1.0 / 2)*algebraic[53]*(states[0] - constants[100]);
		algebraic[62] = ( constants[37]*states[0]*constants[2]*constants[94]*( constants[33]*exp( states[0]*constants[94]) - constants[20]))/(exp( states[0]*constants[94]) - 1.00000);
		algebraic[68] =  algebraic[62]*states[18]*states[19]*states[20]*( constants[9]*(1.00000 - states[21])+ constants[96]*(1.00000 - states[22]));
		algebraic[108] = ((algebraic[50]+algebraic[45]+algebraic[107]+algebraic[54]) -  2.00000*algebraic[43])+algebraic[68]+algebraic[47];
		algebraic[60] = ( constants[35]*states[0]*constants[2]*constants[94]*( states[16]*exp( 2.00000*states[0]*constants[94]) - constants[34]))/(exp( 2.00000*states[0]*constants[94]) - 1.00000);
		algebraic[65] =  constants[9]*algebraic[60]*states[18]*states[19]*states[20]*(1.00000 - states[21]);
		algebraic[83] = ( constants[8]*constants[47]*pow(states[16], 1.60000))/(pow(constants[46], 1.60000)+pow(states[16], 1.60000));
		algebraic[109] =  (1.00000/( 2.00000*constants[94]))*log(constants[34]/states[16]);
		algebraic[110] =  constants[8]*constants[48]*(states[0] - algebraic[109]);
		algebraic[111] = (algebraic[65]+algebraic[110]+algebraic[83]) -  2.00000*algebraic[81];
		algebraic[90] = rates[35]+rates[37];
		algebraic[61] = ( constants[35]*states[0]*constants[2]*constants[94]*( states[17]*exp( 2.00000*states[0]*constants[94]) - constants[34]))/(exp( 2.00000*states[0]*constants[94]) - 1.00000);
		algebraic[66] =  constants[96]*algebraic[61]*states[18]*states[19]*states[20]*(1.00000 - states[22]);
		algebraic[85] = ( constants[95]*constants[47]*pow(states[17], 1.60000))/(pow(constants[46], 1.60000)+pow(states[17], 1.60000));
		algebraic[112] =  (1.00000/( 2.00000*constants[94]))*log(constants[34]/states[17]);
		algebraic[113] =  constants[95]*constants[48]*(states[0] - algebraic[112]);
		algebraic[114] = (algebraic[66]+algebraic[113]+algebraic[85]) -  2.00000*algebraic[82];
		algebraic[91] = rates[36]+rates[38];
		algebraic[116] = algebraic[111]+algebraic[114];
		algebraic[117] = algebraic[103]+algebraic[59]+algebraic[116]+algebraic[108];
		algebraic[10] = ((VoI - constants[4]) -  floor((VoI - constants[4])/constants[6])*constants[6]<=constants[7] ? constants[5] : 0.00000);
		algebraic[67] = algebraic[65]+algebraic[66];
		algebraic[72] = algebraic[69]+algebraic[70];
		algebraic[74] = algebraic[67]+algebraic[68]+algebraic[72];
		algebraic[84] = algebraic[81]+algebraic[82];
		algebraic[87] = algebraic[83]+algebraic[85];
		algebraic[99] = algebraic[94]+algebraic[98];
		algebraic[101] = algebraic[95]+algebraic[100];
		algebraic[115] = algebraic[110]+algebraic[113];
	}

};
