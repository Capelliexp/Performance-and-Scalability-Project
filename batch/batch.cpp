#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
#define PROGRAM_A "./main"

void fkThis(int i, int j);

int main(int argc, char* argv[]){
	char* iterN[4] = {"1", "10", "100", "1000"};
	char* iterBS[11] = {"4", "8", "16", "32", "64", "128", "256", "512", "1024", "2048", "4096"};

	int processID;
	int returnStatus;
	int returnValue;

	int i = 0;
	int j = 0;

	if(argc > 2){
		i = atoi(argv[1]);
		j = atoi(argv[2]);		
	}

	for(int i = 0; i < ARRAY_SIZE(iterN); i++){
		for(int j = 0; j < ARRAY_SIZE(iterBS); j++){

			std::cout << std::endl << "start " << i << " " << j << std::endl;

			if ((processID=fork()) == 0){
				execl(PROGRAM_A, PROGRAM_A, iterN[i], iterBS[j], NULL);
				std::cout << "ERROR: child not created" << std::endl;
				exit(-1);
			}
			waitpid(processID, &returnStatus, 0);
			sleep(1);

			fkThis(i, j);
			sleep(1);

		}
	}

	return 1;
}

void fkThis(int i, int j){
	int returnValue;
	if(i == 0){
		if(j == 0){
			returnValue = system("gprof -p main gmon.out > tests/N1/flatprofileBS4");
			returnValue = system("gprof -q main gmon.out > tests/N1/callgraphBS4");
		}
		else if(j == 1){
			returnValue = system("gprof -p main gmon.out > tests/N1/flatprofileBS8");
			returnValue = system("gprof -q main gmon.out > tests/N1/callgraphBS8");
		}
		else if(j == 2){
			returnValue = system("gprof -p main gmon.out > tests/N1/flatprofileBS16");
			returnValue = system("gprof -q main gmon.out > tests/N1/callgraphBS16");
		}
		else if(j == 3){
			returnValue = system("gprof -p main gmon.out > tests/N1/flatprofileBS32");
			returnValue = system("gprof -q main gmon.out > tests/N1/callgraphBS32");
		}
		else if(j == 4){
			returnValue = system("gprof -p main gmon.out > tests/N1/flatprofileBS64");
			returnValue = system("gprof -q main gmon.out > tests/N1/callgraphBS64");
		}
		else if(j == 5){
			returnValue = system("gprof -p main gmon.out > tests/N1/flatprofileBS128");
			returnValue = system("gprof -q main gmon.out > tests/N1/callgraphBS128");
		}
		else if(j == 6){
			returnValue = system("gprof -p main gmon.out > tests/N1/flatprofileBS256");
			returnValue = system("gprof -q main gmon.out > tests/N1/callgraphBS256");
		}
		else if(j == 7){
			returnValue = system("gprof -p main gmon.out > tests/N1/flatprofileBS512");
			returnValue = system("gprof -q main gmon.out > tests/N1/callgraphBS512");
		}
		else if(j == 8){
			returnValue = system("gprof -p main gmon.out > tests/N1/flatprofileBS1024");
			returnValue = system("gprof -q main gmon.out > tests/N1/callgraphBS1024");
		}
		else if(j == 9){
			returnValue = system("gprof -p main gmon.out > tests/N1/flatprofileBS2048");
			returnValue = system("gprof -q main gmon.out > tests/N1/callgraphBS2048");
		}
		else if(j == 10){
			returnValue = system("gprof -p main gmon.out > tests/N1/flatprofileBS4096");
			returnValue = system("gprof -q main gmon.out > tests/N1/callgraphBS4096");
		}
	}
	else if(i == 1){
		if(j == 0){
			returnValue = system("gprof -p main gmon.out > tests/N10/flatprofileBS4");
			returnValue = system("gprof -q main gmon.out > tests/N10/callgraphBS4");
		}
		else if(j == 1){
			returnValue = system("gprof -p main gmon.out > tests/N10/flatprofileBS8");
			returnValue = system("gprof -q main gmon.out > tests/N10/callgraphBS8");
		}
		else if(j == 2){
			returnValue = system("gprof -p main gmon.out > tests/N10/flatprofileBS16");
			returnValue = system("gprof -q main gmon.out > tests/N10/callgraphBS16");
		}
		else if(j == 3){
			returnValue = system("gprof -p main gmon.out > tests/N10/flatprofileBS32");
			returnValue = system("gprof -q main gmon.out > tests/N10/callgraphBS32");
		}
		else if(j == 4){
			returnValue = system("gprof -p main gmon.out > tests/N10/flatprofileBS64");
			returnValue = system("gprof -q main gmon.out > tests/N10/callgraphBS64");
		}
		else if(j == 5){
			returnValue = system("gprof -p main gmon.out > tests/N10/flatprofileBS128");
			returnValue = system("gprof -q main gmon.out > tests/N10/callgraphBS128");
		}
		else if(j == 6){
			returnValue = system("gprof -p main gmon.out > tests/N10/flatprofileBS256");
			returnValue = system("gprof -q main gmon.out > tests/N10/callgraphBS256");
		}
		else if(j == 7){
			returnValue = system("gprof -p main gmon.out > tests/N10/flatprofileBS512");
			returnValue = system("gprof -q main gmon.out > tests/N10/callgraphBS512");
		}
		else if(j == 8){
			returnValue = system("gprof -p main gmon.out > tests/N10/flatprofileBS1024");
			returnValue = system("gprof -q main gmon.out > tests/N10/callgraphBS1024");
		}
		else if(j == 9){
			returnValue = system("gprof -p main gmon.out > tests/N10/flatprofileBS2048");
			returnValue = system("gprof -q main gmon.out > tests/N10/callgraphBS2048");
		}
		else if(j == 10){
			returnValue = system("gprof -p main gmon.out > tests/N10/flatprofileBS4096");
			returnValue = system("gprof -q main gmon.out > tests/N10/callgraphBS4096");
		}
	}
	else if(i == 2){
		if(j == 0){
			returnValue = system("gprof -p main gmon.out > tests/N100/flatprofileBS4");
			returnValue = system("gprof -q main gmon.out > tests/N100/callgraphBS4");
		}
		else if(j == 1){
			returnValue = system("gprof -p main gmon.out > tests/N100/flatprofileBS8");
			returnValue = system("gprof -q main gmon.out > tests/N100/callgraphBS8");
		}
		else if(j == 2){
			returnValue = system("gprof -p main gmon.out > tests/N100/flatprofileBS16");
			returnValue = system("gprof -q main gmon.out > tests/N100/callgraphBS16");
		}
		else if(j == 3){
			returnValue = system("gprof -p main gmon.out > tests/N100/flatprofileBS32");
			returnValue = system("gprof -q main gmon.out > tests/N100/callgraphBS32");
		}
		else if(j == 4){
			returnValue = system("gprof -p main gmon.out > tests/N100/flatprofileBS64");
			returnValue = system("gprof -q main gmon.out > tests/N100/callgraphBS64");
		}
		else if(j == 5){
			returnValue = system("gprof -p main gmon.out > tests/N100/flatprofileBS128");
			returnValue = system("gprof -q main gmon.out > tests/N100/callgraphBS128");
		}
		else if(j == 6){
			returnValue = system("gprof -p main gmon.out > tests/N100/flatprofileBS256");
			returnValue = system("gprof -q main gmon.out > tests/N100/callgraphBS256");
		}
		else if(j == 7){
			returnValue = system("gprof -p main gmon.out > tests/N100/flatprofileBS512");
			returnValue = system("gprof -q main gmon.out > tests/N100/callgraphBS512");
		}
		else if(j == 8){
			returnValue = system("gprof -p main gmon.out > tests/N100/flatprofileBS1024");
			returnValue = system("gprof -q main gmon.out > tests/N100/callgraphBS1024");
		}
		else if(j == 9){
			returnValue = system("gprof -p main gmon.out > tests/N100/flatprofileBS2048");
			returnValue = system("gprof -q main gmon.out > tests/N100/callgraphBS2048");
		}
		else if(j == 10){
			returnValue = system("gprof -p main gmon.out > tests/N100/flatprofileBS4096");
			returnValue = system("gprof -q main gmon.out > tests/N100/callgraphBS4096");
		}
	}
	else if(i == 3){
		if(j == 0){
			returnValue = system("gprof -p main gmon.out > tests/N1000/flatprofileBS4");
			returnValue = system("gprof -q main gmon.out > tests/N1000/callgraphBS4");
		}
		else if(j == 1){
			returnValue = system("gprof -p main gmon.out > tests/N1000/flatprofileBS8");
			returnValue = system("gprof -q main gmon.out > tests/N1000/callgraphBS8");
		}
		else if(j == 2){
			returnValue = system("gprof -p main gmon.out > tests/N1000/flatprofileBS16");
			returnValue = system("gprof -q main gmon.out > tests/N1000/callgraphBS16");
		}
		else if(j == 3){
			returnValue = system("gprof -p main gmon.out > tests/N1000/flatprofileBS32");
			returnValue = system("gprof -q main gmon.out > tests/N1000/callgraphBS32");
		}
		else if(j == 4){
			returnValue = system("gprof -p main gmon.out > tests/N1000/flatprofileBS64");
			returnValue = system("gprof -q main gmon.out > tests/N1000/callgraphBS64");
		}
		else if(j == 5){
			returnValue = system("gprof -p main gmon.out > tests/N1000/flatprofileBS128");
			returnValue = system("gprof -q main gmon.out > tests/N1000/callgraphBS128");
		}
		else if(j == 6){
			returnValue = system("gprof -p main gmon.out > tests/N1000/flatprofileBS256");
			returnValue = system("gprof -q main gmon.out > tests/N1000/callgraphBS256");
		}
		else if(j == 7){
			returnValue = system("gprof -p main gmon.out > tests/N1000/flatprofileBS512");
			returnValue = system("gprof -q main gmon.out > tests/N1000/callgraphBS512");
		}
		else if(j == 8){
			returnValue = system("gprof -p main gmon.out > tests/N1000/flatprofileBS1024");
			returnValue = system("gprof -q main gmon.out > tests/N1000/callgraphBS1024");
		}
		else if(j == 9){
			returnValue = system("gprof -p main gmon.out > tests/N1000/flatprofileBS2048");
			returnValue = system("gprof -q main gmon.out > tests/N1000/callgraphBS2048");
		}
		else if(j == 10){
			returnValue = system("gprof -p main gmon.out > tests/N1000/flatprofileBS4096");
			returnValue = system("gprof -q main gmon.out > tests/N1000/callgraphBS4096");
		}
	}
	else{
		std::cout << "ERROR: no gprof file produced" << std::endl;
	}
}