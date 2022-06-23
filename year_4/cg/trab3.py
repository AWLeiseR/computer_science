import cv2
import numpy as nmp
import matplotlib.pyplot as plt

def getHist(blueMat,greenMat,redMat,imgWith,imgLength):

  for y in range(0, imgLength):
      for x in range(0, imgWith):
          blue = blueMat.item(x, y) 
          green = greenMat.item(x, y) 
          red = redMat.item(x, y) 
         


def main():
  img= cv2.imread('lena.png')
  blue, green, red = cv2.split(img)
  imgWith, imgLength, colors = img.shape


main()