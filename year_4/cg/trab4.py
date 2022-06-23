import cv2
import numpy as nmp
import matplotlib.pyplot as plt

def showImage(img):
  cv2.imshow('imagem',img)
  cv2.waitKey(0)

def getHist(blueMat,imgWith,imgLength):
  blueHist  = [0 for i in range(256)] 
  for y in range(0, imgLength):
      for x in range(0, imgWith):
          blue = blueMat.item(x, y) 
          blueHist[blue]+=1
  return blueHist

def normalizeHist(histArray,numTotalPixels):
  normalizedHist =[]
  for i in range(0,256):
    normalizedHist.append( histArray[i]/numTotalPixels)
  return normalizedHist

def sumProbabilities(t,hist):
  sumedProbability = 0
  for i in range(0,t):
    sumedProbability += hist[i]
  return sumedProbability,1-sumedProbability

def averageIntensityC1(t,hist):
  upPart = 1
  downPart = 1
  for i in range(0,t):
    upPart += hist[i]*i
    downPart += hist[i]
  return upPart/downPart

def averageIntensityC2(t,hist):
  upPart = 1
  downPart = 1
  for i in range(t,256):
    upPart += hist[i]*i
    downPart += hist[i]
  return upPart/downPart

def generalAverageIntensity(hist):
  upPart = 1
  downPart = 1
  for i in range(0,256):
    upPart += hist[i]*i
    downPart += hist[i]
  return upPart/downPart

def variance(probabilityC1,probabilityC2,averageC1,averageC2,generalAverage):
  pC1minusGA = (averageC1-generalAverage)**2
  pC2minusGA = (averageC2-generalAverage)**2
  return probabilityC1 * pC1minusGA + probabilityC2 * pC2minusGA

def imageResult(blueMat,imgWith,imgLength, t):
  result = blueMat 
  for y in range(0, imgLength):
      for x in range(0, imgWith):
          blue = blueMat.item(x, y) 
          if blue > t:
            result.itemset((x, y),255)
          else:   
            result.itemset((x, y),0)   
  return result

def plotGraph(rangeGraph,blue):
  fig, ax = plt.subplots()  
  ax.plot(rangeGraph, blue, label='Azul',color='blue')  
  ax.set_xlabel('indices blue')  
  ax.set_ylabel('Quantidade')  
  ax.set_title("Histograma")  
  ax.legend()  

def main():
  img= cv2.imread('lena.png')
  blue, green, red = cv2.split(img)
  imgWith, imgLength, colors = img.shape
  blueHist = getHist(blue,imgWith,imgLength)
  normalizeddBlue = normalizeHist(blueHist,imgWith*imgLength)
  t = 0
  maxVariance = 0
  for i in range(1,256):
    sumProbC1, sumProbC2 = sumProbabilities(i,normalizeddBlue)
    averageC1 = averageIntensityC1(t, blueHist)
    averageC2 = averageIntensityC2(t, blueHist)
    general = generalAverageIntensity(blueHist)
    currentVariance = variance(sumProbC1,sumProbC2,averageC1,averageC2,general)
    print(currentVariance)
    if currentVariance > maxVariance:
      t = i
  result = imageResult(blue,imgWith,imgLength,t)
  showImage(result)

main()