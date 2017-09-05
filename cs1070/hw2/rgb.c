/**
 * Name		: Lukas Herman
 * Course	: CPSC 1070-001
 * Assignment #	: Homework #2
 * Due Date	: February 16, 2017
 * Description	: This program will check the input value if it is a valid 
 * 		  RGB value.
 */

#include "rgb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

color_t readColor(FILE *infp){
   color_t colorType;
 
   /* Range for rgb values */
   int lowLim = 0;
   int upLim = 255;   

   int i;
   int n;

   int r; // red field
   int g; // green field
   int b; // blue field

   char colorName[8];
   unsigned int hexValue;

   /**
    * These two arrays are parallel. 
    * Each element in wellknownRGBs array contains another array which holds
    * RGB values respectively.
    */   
   char *wellknownColors[] = {"white", "red", "blue", "purple",
                              "black", "green", "orange", "yellow"};

   int wellknownRGBs[][3] = {{255, 255, 255}, {255, 0, 0}, 	// white red 
                           {0, 0, 255}, {128, 0, 255},		// blue purple
                           {0, 0, 0}, {0, 255, 0},		// black green
                           {255, 128, 0}, {255, 255, 0}};	// orange yellow

   int nWellknownColors = 8;
   int isFound = 0; // 1 is for true. Other number is false

   /** 
    * This condition will check if all the RGB values are within range.
    * If it is, then it'll assign the RGB values to the struct respectively.
    */
   if((n = fscanf(infp, "%d %d %d", &r, &g, &b)) == 3){
      if((r >= lowLim && r <= upLim) && 
         (g >= lowLim && g <= upLim) &&
         (b >= lowLim && b <= upLim)){
         
         colorType.r = r;
         colorType.g = g;
         colorType.b = b;
      }
      else{
         fprintf(stderr, "The input values are not within valid RGB range\n");
         exit(EXIT_FAILURE);
      }
   }

   /**
    * This condition is to check if there is no value has been read. Then,
    * check if the value is a string. If it is, then it'll check if it is
    * in hexadecimal form or a "well-know" color name (e.g. "red").
    */
   else if(n == 0){
      fscanf(infp, "%s", colorName);

      if(colorName[0] == '#'){
         // Validate the hex value
         if(sscanf(colorName + 1, "%x", &hexValue) == 1){
            colorType.r = hexValue >> 16;
            colorType.g = (hexValue >> 8) & 0xff;
            colorType.b = hexValue & 0xff;
         }
         else{
            fprintf(stderr, "The hex value is not valid\n");
            exit(EXIT_FAILURE);
         }
      }
      else{
         // A loop to check if the color is in the well-known colors
         for(i = 0; isFound != 1 && i < nWellknownColors; i++){
            if(strcasecmp(colorName, wellknownColors[i]) == 0){
               isFound = 1;   
               colorType.r = wellknownRGBs[i][0];
               colorType.g = wellknownRGBs[i][1];
               colorType.b = wellknownRGBs[i][2];
            }
         }

         // Exit the program if the color is not found
         if(isFound != 1){
            fprintf(stderr, "The color is not well-known\n");
            exit(EXIT_FAILURE);
         }      
      }
   }
   else{
      fprintf(stderr, "The input values are not valid\n");
      exit(EXIT_FAILURE);
   } 
   
   return colorType;
   
}
