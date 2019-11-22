/* Author:  Jake May   45436126
*           jake.may@students.mq.edu.au
*  Date: 1/09/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRUCTSIZE 65
#define TEMPSTRUCTSIZE 45

struct list {
  unsigned short expansion;
  char scene;
  unsigned int bath;
  double ink;
  double kick;
  char trees;
  unsigned int owner;
  long int room;
  char baseball[9];
  short int feast;
  short int vacation;
  short int fact;
  char giants;
  float flower;
  long int quill;
  char dog;
};

struct tempList{ //45
  double expansion; //8
  char scene; //1
  char bath; //1
  float ink; //4
  float kick;//4
  short trees; //2
  char owner; //1
  char room; //1
  char baseball[8]; //8
  char feast; //1
  // char vacation; //1
  // char fact; //1
  // char giants; //1
  double flower; //8
  char quill; //1
  short dog; //2
};

void usage(){
  fprintf(stderr, "No arguments provided");
  exit(1);
}

int main(int argc, char **argv){
  FILE *fptrR;
  FILE *fptrW;
  struct tempList *temp;

  // exit with error if no parameters supplied
  if(argc < 2){
    usage();
  }

  fptrR = fopen(argv[1], "rb");
  fptrW = fopen(argv[2], "wb");

  // exit with error if no input
  if(fptrR < 0 || fptrR == NULL){
    fprintf(stderr, "Can't open file, %s", argv[1]);
    exit(1);
  }

    fseek(fptrR, 0, SEEK_END);
    long fileSize = ftell(fptrR);
    fseek(fptrR, 0, SEEK_SET);


    long lineCount = fileSize/sizeof(struct tempList);
	
  struct list stage4[lineCount];
  
  temp = malloc(fileSize * lineCount + (sizeof(struct tempList)));



  // while(fread first field){
  //   fread(second field)
  //   ...
  //   casts to OG struct from temp struct
  //   ...
  //   useless prints
  //   ...
  //   fwrites
  // }
  int i = 0;
  while(1){
    fread(&temp[i].expansion, sizeof(temp[i].expansion), 1, fptrR);
    fread(&temp[i].scene, sizeof(temp[i].scene), 1, fptrR);
    fread(&temp[i].bath, sizeof(temp[i].bath), 1, fptrR);
    fread(&temp[i].ink, sizeof(temp[i].ink), 1, fptrR);
    fread(&temp[i].kick, sizeof(temp[i].kick), 1, fptrR);
    fread(&temp[i].trees, sizeof(temp[i].trees), 1, fptrR);
    fread(&temp[i].owner, sizeof(temp[i].owner), 1, fptrR);
    fread(&temp[i].room, sizeof(temp[i].room), 1, fptrR);
    fread(&temp[i].baseball, sizeof(temp[i].baseball), 1, fptrR);
    fread(&temp[i].feast, sizeof(temp[i].feast), 1, fptrR);
    // fread(&temp[i].vacation, sizeof(temp[i].vacation), 1, fptrR);
    // fread(&temp[i].fact, sizeof(temp[i].fact), 1, fptrR);
    // fread(&temp[i].giants, sizeof(temp[i].giants), 1, fptrR);
    fread(&temp[i].flower, sizeof(temp[i].flower), 1, fptrR);
    fread(&temp[i].quill, sizeof(temp[i].quill), 1, fptrR);
    fread(&temp[i].dog, sizeof(temp[i].dog), 1, fptrR);
	
	if(feof(fptrR)){
		break;
	}
	i++;
  }
    struct list stage4[i];

  
  int size = i;
  i = 0;
//
  for(i = 0; i < size; i++){
    stage4[i].expansion = (unsigned short)temp[i].expansion;
    stage4[i].scene = (char)temp[i].scene;
    stage4[i].bath = (unsigned int)temp[i].bath;
    stage4[i].ink = (double)temp[i].ink;
    stage4[i].kick = (double)temp[i].kick;
    stage4[i].trees = (char)temp[i].trees;
    stage4[i].owner = (unsigned int)temp[i].owner;
    stage4[i].room = (long int)temp[i].room;
    strncpy(stage4[i].baseball, temp[i].baseball, 9);
    stage4[i].feast = (short)temp[i].feast;
    stage4[i].vacation = (short)0;
    stage4[i].fact = (short)0;
    stage4[i].giants = (char)0;
    stage4[i].flower = (float)temp[i].flower;
    stage4[i].quill = (long)temp[i].quill;
    stage4[i].dog = (char)temp[i].dog;
  }
  
  i = 0;

  for(i = 0; i < size; i++){
    fwrite(&stage4[i].expansion, sizeof(stage4[i].expansion), 1, fptrW);
    fwrite(&stage4[i].scene, sizeof(stage4[i].scene), 1, fptrW);
    fwrite(&stage4[i].bath, sizeof(stage4[i].bath), 1, fptrW);
    fwrite(&stage4[i].ink, sizeof(stage4[i].ink), 1, fptrW);
    fwrite(&stage4[i].kick, sizeof(stage4[i].kick), 1, fptrW);
    fwrite(&stage4[i].trees, sizeof(stage4[i].trees), 1, fptrW);
    fwrite(&stage4[i].owner, sizeof(stage4[i].owner), 1, fptrW);
    fwrite(&stage4[i].room, sizeof(stage4[i].room), 1, fptrW);
    fwrite(&stage4[i].baseball, sizeof(stage4[i].baseball), 1, fptrW);
    fwrite(&stage4[i].feast, sizeof(stage4[i].feast), 1, fptrW);
    fwrite(&stage4[i].vacation, sizeof(stage4[i].vacation), 1, fptrW);
    fwrite(&stage4[i].fact, sizeof(stage4[i].fact), 1, fptrW);
    fwrite(&stage4[i].giants, sizeof(stage4[i].giants), 1, fptrW);
    fwrite(&stage4[i].flower, sizeof(stage4[i].flower), 1, fptrW);
    fwrite(&stage4[i].quill, sizeof(stage4[i].quill), 1, fptrW);
    fwrite(&stage4[i].dog, sizeof(stage4[i].dog), 1, fptrW);
  }

  free(temp);
  // free(stage4);
  fclose(fptrR);
  fclose(fptrW);
  return 0;
}
