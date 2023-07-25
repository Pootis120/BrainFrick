#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

int main() {
  char* text = ReadFile("source.txt");
  
  printf("%s\n", text);
  free(text);
  return 0;
} 