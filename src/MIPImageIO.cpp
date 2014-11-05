/** \file MIPImageIO.cpp
 *
 * Module:    CS3303
 *            Medizinische Bild- und Signalverarbeitung
 *            Medizinische Bildverarbeitung
 *
 * Authors:   Jan Ehrhardt, Alexander Schmidt-Richberg
 *
 * Student:   TODO Fill in your name(s) here
 *
 * Matr.-No.: TODO Fill in your matriculation number(s) here
 *
 * Copyright (c) 2010 Institute of Medical Informatics,
 *            University of Luebeck
 ********************************************************/
#include <iostream>

#include "Image.h"
#include "ImageIO.h"

int main( int argc, char *argv[] )
{
  std::cout << "==========================" << std::endl;
  std::cout << "        MIPImageIO        " << std::endl;
  std::cout << "==========================" << std::endl;

  // Check if program is called correctly.
  if( argc != 3 )
  {
    std::cout << "Error: MIPImageIO called incorrectly!" << std::endl;
    std::cout << "Usage: MIPImageIO inimage.mha outimage.mha" << std::endl;
    return -1;
  }

  // Declare an image.
  Image* image = new Image();

  // Read image using ImageIO.
  std::cout << "Reading image " << argv[1] << "..." << std::endl;
  if( !ImageIO::Read( argv[1], image ) )
  {
    std::cout << "Error: Reading image failed!" << std::endl;
    return -1;
  }

  /*
   * TODO: Task 5: Add code to compute minimal and maximal gray value in
   * the image and print this value to stdout.
   */
  Image::PixelType maximumValue = 0;
  Image::PixelType minimumValue = 0;

  std::cout << "Maximum gray value: " << maximumValue << std::endl;
  std::cout << "Minimum gray value: " << minimumValue << std::endl;

  /*
   * TODO: Task 6: Add code to flip the input image horizontally (along y-axis)
   */

  // Write image using ImageIO.
  std::cout << "Writing image " << argv[2] << std::endl;
  if( !ImageIO::Write( argv[2], image ) )
  {
    std::cout << "Error: Writing image failed!" << std::endl;
    return -1;
  }

  // Delete image to free space.
  delete image;

  std::cout << "==========================" << std::endl;
  return 0;
}
