import cv2
import numpy as nmp
import matplotlib.pyplot as plt

def plotGraph(rangeGraph,red,green,blue):
  fig, ax = plt.subplots()  # Create a figure and an axes.
  ax.plot(rangeGraph, red, label='Vermelho', color='red')  # Plot some data on the axes.
  ax.plot(rangeGraph, green, label='Verde',color='green')  # Plot more data on the axes...
  ax.plot(rangeGraph, blue, label='Azul',color='blue')  # ... and some more.
  ax.set_xlabel('indices RGB')  # Add an x-label to the axes.
  ax.set_ylabel('Quantidade')  # Add a y-label to the axes.
  ax.set_title("Histograma")  # Add a title to the axes.
  ax.legend()  # Add a legend.

def getHist(blueMat,greenMat,redMat,imgWith,imgLength):
  blueHist  = [0 for i in range(256)] 
  greenHist  = [0 for i in range(256)] 
  redHist  = [0 for i in range(256)] 
  for y in range(0, imgLength):
      for x in range(0, imgWith):
          blue = blueMat.item(x, y) 
          green = greenMat.item(x, y) 
          red = redMat.item(x, y) 
          blueHist[blue]+=1
          greenHist[green]+=1
          redHist[red]+=1
  return redHist,greenHist,blueHist

def normalizeHist(histArray,numTotalPixels):
  normalizedHist =[]
  for i in range(0,256):
   normalizedHist.append( histArray[i]/numTotalPixels)
  return normalizedHist

def acumulateHist(histArray):
  equalizatedHist = []
  for i in range(0,256):
    equalizatedHist.append(sumHist(histArray,i))
  for i in range(0,256):
    equalizatedHist[i]= equalizatedHist[i]
  return equalizatedHist

def sumHist(histArray,sumUntil):
  result = 0
  for i in range(0,sumUntil):
    result += histArray[i]
  return result

# nova[i][j] = 255 * acc[velha[i][j]]

def getNewImage(blue,green,red,imgWith,imgLength,acumulatedRed,acumulatedGreen,acumulatedBlue):
  newBlue = blue
  newGreen = green
  newRed = red
  for y in range(0, imgLength):
        for x in range(0, imgWith):
          newBlue.itemset((x, y), 255 * acumulatedBlue[blue.item(x,y)])
          newGreen.itemset((x, y), 255 * acumulatedGreen[green.item(x,y)])
          newRed.itemset((x, y), 255 * acumulatedRed[red.item(x,y)])
  return newBlue,newGreen,newRed
  

def showImage(img):
  cv2.imshow('imagem',img)
  cv2.waitKey(0)


def main():
  img= cv2.imread('lena.png')
  blue, green, red = cv2.split(img)
  imgWith, imgLength, colors = img.shape
  redHist,greenHist,blueHist = getHist(blue,green,red,imgWith,imgLength)
  plotGraph([i for i in range(256)],redHist,greenHist,blueHist)
  normalizeddRed = normalizeHist(redHist,imgWith*imgLength)
  acumulatedRed = acumulateHist(normalizeddRed)
  normalizedGreen = normalizeHist(greenHist,imgWith*imgLength)
  acumulatedGreen = acumulateHist(normalizedGreen)
  normalizedBlue = normalizeHist(blueHist,imgWith*imgLength)
  acumulatedBlue = acumulateHist(normalizedBlue)
  newBlue, newGreen, newRed = getNewImage(blue,green,red,imgWith,imgLength,acumulatedRed,acumulatedGreen,acumulatedBlue)
  newRedHist,newGreenHist,newBlueHist = getHist(newBlue,newGreen,newRed,imgWith,imgLength)
  showImage(cv2.merge([newBlue,newGreen,newBlue]))
  plotGraph([i for i in range(256)],newRedHist,newGreenHist,newBlueHist)
  plt.show()

main()