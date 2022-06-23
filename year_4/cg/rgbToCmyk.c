#include <stdio.h>

float normalize(int rgbColor) { 
  return (rgbColor / 255); 
}

int findK(float cyan, float magenta, float yellow) {
  if(cyan < magenta){
    if(cyan < yellow){
      return cyan;
    }
    return yellow;
  }else{
    if(magenta < yellow){
      return magenta;
    }
    return yellow;
  }
}

float newCMYK(float color, int k){
  if(k>1){
    return 0;
  }else{
    return ((color-k)/(1-k));
  }
}