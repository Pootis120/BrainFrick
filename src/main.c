#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void ASSERT(bool initialized, char* messageOnFail) 
{
  if (!initialized) 
  {
    printf("%s", messageOnFail);
  }
}

char* ReadFile(char* filePath) 
{
  FILE* inputFile;
  char* outtext;
  long numbytes;

  inputFile = fopen("source.txt", "r");
  ASSERT(inputFile, "Error: Could not open file");
  fseek(inputFile, 0L, SEEK_END);
  numbytes = ftell(inputFile);
  fseek(inputFile, 0L, SEEK_SET);

  outtext = (char*)calloc(numbytes, sizeof(char));
  ASSERT(outtext, "Could not initialize text");
  fread(outtext, sizeof(char), numbytes, inputFile);
  fclose(inputFile);

  return outtext;
}

//commit to github: feat: made struct and interpreter

struct MemoryVars 
{
  int Pc;
  int* memory;
};

void Interpret(char* sourceCode) 
{
  struct MemoryVars mem;
  mem.memory = (int*)calloc(100 * sizeof(int), sizeof(int));
  mem.Pc = 0;
  for (int i = 0, max = strlen(sourceCode); i < max; i++) 
  {
    switch (sourceCode[i]) 
    {
      case '>' :
        mem.Pc++;
        break;
      case '<' :
        mem.Pc--;
        break;
      case '+' :
        mem.memory[mem.Pc]++;
        break;
      case '-' :
        mem.memory[mem.Pc]--;
        break;
      case '.' :
        putchar(mem.memory[mem.Pc]);
        break;
      case ',' :
        mem.memory[mem.Pc] = getchar();
        break;
      default:
        break;
    }
  }
}

int main() {
  char* text = ReadFile("source.txt");
  Interpret(text);
  
  printf("\n");
  free(text);
  return 0;
} 