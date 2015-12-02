%{
	int currentFile = 0;
	int totalInputFile = 0;
	FILE *myfile = NULL;
	char * inputFile;
	char ** argvTmp;
%}

%%


^(G|g)(R|r)(P|p)(\-|[ ])[1-9].*		{printf("%s\n", yytext);}

<<EOF>>								{
										printf("End Of File %s, which was input file number %d , has been reached\n", inputFile,currentFile);
										printf("Looking ahead for another file..");
										if(currentFile == totalInputFile){
											yyterminate();
										}else{
											currentFile++;
											inputFile = argvTmp[currentFile];
											myfile = fopen(inputFile, "r");
											if (!myfile) {
												printf("%s\n","I can't open the specified file!");
												return -1;
											}
											// set lex to read from it instead of defaulting to STDIN:
											yyin = myfile;
										}
									}

.				//{printf("%s - %s\n", yytext, "not matching");}
\n

%%


int main(int argc, char ** argv){
	if(argc < 2){
		printf("%s\n","Usage is compiled_file input_file");
		return -1;
	}
	argvTmp = argv; //raw pointer copy
	// open a file handle to a particular file:
	currentFile = 1;
	totalInputFile = argc - currentFile;
	inputFile = argvTmp[currentFile];
	myfile = fopen(inputFile, "r");
	// make sure it's valid:
	if (!myfile) {
		printf("%s\n","I can't open the specified file!");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// lex through the input:
	yylex();



}