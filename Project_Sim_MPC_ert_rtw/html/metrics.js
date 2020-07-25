function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "C:\\Users\\admin\\Documents\\MATLAB\\Examples\\mpc_featured\\Project_Sim_MPC_ert_rtw\\Project_Sim_MPC.c",
	size: 154};
	 this.metricsArray.var["rtM_"] = {file: "C:\\Users\\admin\\Documents\\MATLAB\\Examples\\mpc_featured\\Project_Sim_MPC_ert_rtw\\Project_Sim_MPC.c",
	size: 585};
	 this.metricsArray.var["rtX"] = {file: "C:\\Users\\admin\\Documents\\MATLAB\\Examples\\mpc_featured\\Project_Sim_MPC_ert_rtw\\Project_Sim_MPC.c",
	size: 32};
	 this.metricsArray.fcn["Project_Sim_MPC.c:rt_ertODEUpdateContinuousStates"] = {file: "C:\\Users\\admin\\Documents\\MATLAB\\Examples\\mpc_featured\\Project_Sim_MPC_ert_rtw\\Project_Sim_MPC.c",
	stack: 104,
	stackTotal: -1};
	 this.metricsArray.fcn["Project_Sim_MPC_derivatives"] = {file: "C:\\Users\\admin\\Documents\\MATLAB\\Examples\\mpc_featured\\Project_Sim_MPC_ert_rtw\\Project_Sim_MPC.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["Project_Sim_MPC_initialize"] = {file: "C:\\Users\\admin\\Documents\\MATLAB\\Examples\\mpc_featured\\Project_Sim_MPC_ert_rtw\\Project_Sim_MPC.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Project_Sim_MPC_step"] = {file: "C:\\Users\\admin\\Documents\\MATLAB\\Examples\\mpc_featured\\Project_Sim_MPC_ert_rtw\\Project_Sim_MPC.c",
	stack: 485,
	stackTotal: -1};
	 this.metricsArray.fcn["memcpy"] = {file: "C:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["memset"] = {file: "C:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="Project_Sim_MPC_metrics.html">Global Memory: 771(bytes) Maximum Stack: 485(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
