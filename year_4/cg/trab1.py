import cv2
import numpy as nmp

def showImage(img):
  cv2.imshow('imagem',img)
  cv2.waitKey(0)

def normalize(rgbColor): 
  return (rgbColor / 255) 

def findCMY(color):
  return 1 - color

def findK(cyan, magenta, yellow):
    return min(cyan, magenta, yellow)

def newCMYK(color, k):
  if k >=1 :
    return 0
  else:
    return ((color-k)/(1-k))

def transformRGBToCMYK(red,green,blue):
  newRed = normalize(red)
  newGreen = normalize(green)
  newBlue = normalize(blue)
  cyanWithoutK = findCMY(newRed)
  magentaWithoutK = findCMY(newGreen)
  yellowWithoutK = findCMY(newBlue)
  colorK = findK(cyanWithoutK,magentaWithoutK,yellowWithoutK)
  cyan = newCMYK(cyanWithoutK,colorK)
  magenta = newCMYK(magentaWithoutK,colorK)
  yellow = newCMYK(yellowWithoutK,colorK)
  return 100*cyan,100*magenta,100*yellow,nmp.ceil(100*colorK)

def getImageInCMYK(blueMat,greenMat,redMat,imgWith,imgLength):
  cyanMat = blueMat
  magentaMat = greenMat
  yellowMat = redMat
  kMat = redMat
  for y in range(0, imgLength):
      for x in range(0, imgWith):
          blue = blueMat.item(x, y) 
          green = greenMat.item(x, y) 
          red = redMat.item(x, y) 
          cyan,magenta,yellow,colorK = transformRGBToCMYK(red,green,blue)
          cyanMat.itemset((x, y), cyan) 
          magentaMat.itemset((x, y), magenta) 
          yellowMat.itemset((x, y), yellow) 
          kMat.itemset((x, y), colorK) 
  return cyanMat, magentaMat, yellowMat, kMat

def findI(normalizeR,normalizeG,normalizeB):
  return ( normalizeR + normalizeG + normalizeB ) / 3

def findS(normalizeR,normalizeG,normalizeB):
  sum = ( normalizeR + normalizeG + normalizeB )
  if sum == 0:
    return  1 - ( min(normalizeR,normalizeG,normalizeB) * 0  )
  else:
    return  1 - ( min(normalizeR,normalizeG,normalizeB) * ( 3 / ( normalizeR + normalizeG + normalizeB ) ) )

def findH(normalizeR,normalizeG,normalizeB):
  superior = (( normalizeR - normalizeG ) + ( normalizeR - normalizeB )) / 2
  inferior = nmp.sqrt((( normalizeR - normalizeG )**2) + ( ( normalizeR - normalizeB ) * ( normalizeG - normalizeB )))
  if inferior == 0:
    teta = nmp.arccos(0)
  else:
    teta = nmp.arccos(superior/inferior)
  
  if normalizeB <= normalizeG:
    return teta
  else:
    return 360 - teta

def transformRGBToHSI(red,green,blue):
  normalizeR = normalize(red)
  normalizeG = normalize(green)
  normalizeB = normalize(blue)
  H = findH(normalizeR,normalizeG,normalizeB)
  S = findS(normalizeR,normalizeG,normalizeB)
  I = findI(normalizeR,normalizeG,normalizeB)
  return H, S, I

def getImageInHSI(blueMat,greenMat,redMat,imgWith,imgLength):
  HMat = blueMat
  SMat = greenMat
  IMat = redMat
  
  for y in range(0, imgLength):
      for x in range(0, imgWith):
          blue = blueMat.item(x, y) 
          green = greenMat.item(x, y) 
          red = redMat.item(x, y) 
          H,S,I = transformRGBToHSI(red,green,blue)
          HMat.itemset((x, y), H*100) 
          SMat.itemset((x, y), S*100) 
          IMat.itemset((x, y), I*100) 
  return HMat, SMat, IMat

def main():
  img= cv2.imread('lena.png')
  blue, green, red = cv2.split(img)
  imgWith, imgLength, colors = img.shape
  print(transformRGBToHSI(66,135,245))
  
  # print(imgWith, imgLength, colors)
  # [cyan,magenta,yellow,k] = getImageInCMYK(blue, green, red, imgWith, imgLength)
  # showImage(cv2.merge([cyan,magenta,yellow,k]))
  [H,S,I] = getImageInHSI(blue, green, red, imgWith, imgLength)
  showImage(cv2.merge([H,S,I]))
  

main()