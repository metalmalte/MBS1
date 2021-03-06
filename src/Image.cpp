/** \file Image.cpp
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
#include "Image.h"   // Include the header file.
#include <iostream>  // Include for printing text to the screen.
#include <fstream>   // Include for reading and writing files.
#include <string.h>  // Include for string handling.
#include <vector>    // Include for vector handling.

/* Constructor of an image. Creates an image of zero size without
 * allocating the image buffer.*/
Image::Image()
{
  // Create an empty image with zero-size.
  m_SizeX = 0;
  m_SizeY = 0;

  m_SpacingX = 1.0;
  m_SpacingY = 1.0;

  m_ImageBuffer = NULL;
}

/* Constructor of an image. Using this constructor an image of
 * the given size filled with zero-values is created. */
Image::Image( const unsigned int x, const unsigned int y )
{
  m_SizeX = x;
  m_SizeY = y;

  m_SpacingX = 1.0;
  m_SpacingY = 1.0;

  unsigned int size = m_SizeX * m_SizeY;

  if( size > 0 )
  {
    // Allocate the image buffer.
    m_ImageBuffer = new PixelType[size];

    // Initialize with zero values.
    memset( m_ImageBuffer, 0, size * sizeof(PixelType) );

    // Allocate a new reference counter for this image buffer and set to 1.
  }
  else
  {
    // If this is a zero-size image, do not allocate.
    m_ImageBuffer = NULL;
  }
}

// Destructor
Image::~Image()
{
  // free allocated memory
  ReleaseData();
}

/* Get the value of the pixel at coordinate (x, y). The coordinates will be
 * converted into an linearized index internally. */
Image::PixelType Image::GetPixel( const unsigned int x, const unsigned int y ) const
{
  /*
   * TODO: Task 4: return the value at the correct position in the image buffer.
   * return 0, if x,y are not correct indices.
   */

  return 0;
}

/* Get the value of the pixel at index i. */
Image::PixelType Image::GetPixel( const unsigned int i ) const
{
  // Test if in bounds.
  if( i >= m_SizeX * m_SizeY )
  {
    return 0;
  }

  return m_ImageBuffer[i];
}

/* Set the value of the pixel at coordinate (x, y). The coordinates will be
 * converted into an linearized index internally.
 *
 * Returns success of the operation. */
bool Image::SetPixel( const unsigned int x, const unsigned int y, const PixelType value )
{

  /*
   * TODO: Task 4: set the value at the correct position in the image buffer.
   * return true, if x,y are correct indices, false otherwise
   */

  return false;
}

/* Set the value of the pixel at index i.
 *
 * Returns success of the operation. */
bool Image::SetPixel( const unsigned int i, const PixelType value )
{
  // Test if in bounds.
  if( i >= m_SizeX * m_SizeY )
  {
    return false;
  }

  m_ImageBuffer[i] = value;

  return true;
}

/* Set the spacing of the image. */
void Image::SetSpacing( const double sx, const double sy )
{
  m_SpacingX = sx;
  m_SpacingY = sy;
}

void Image::Print()
{
  std::cout << "Image: [" << m_SizeX << "x" << m_SizeY << "] (" << m_SpacingX << "," << m_SpacingY << ")\n";
}

// Create this as an empty image of the given size.
bool Image::Allocate( const unsigned int x, const unsigned int y )
{
  ReleaseData();

  m_SizeX = x;
  m_SizeY = y;

  unsigned int size = m_SizeX * m_SizeY;

  if( size > 0 )
  {
    // Allocate the image buffer.
    m_ImageBuffer = new PixelType[size];

    // Initialize with zero values.
    memset( m_ImageBuffer, 0, size * sizeof(PixelType) );
  }
  else
  {
    // If this is a zero-size image, do not allocate.
    m_ImageBuffer = NULL;

    return false;
  }

  return true;
}

// Makes a new copy of this image.
bool Image::CloneImage( const Image* other )
{
  // Check if other image is NULL.
  if( other == NULL )
  {
    std::cout << "Error: Could not copy from NULL pointer!" << std::endl;
    return false;
  }

  // Check if images are the same.
  if( this == other )
  {
    return true;
  }

  // Check if reallocation is required.
  unsigned int otherSizeX = other->GetSizeX();
  unsigned int otherSizeY = other->GetSizeY();
  if( m_SizeX != otherSizeX || m_SizeY != otherSizeY )
  {
    this->Allocate( otherSizeX, otherSizeY );
  }

  // Check if spacing has to be changed.
  if( m_SpacingX != other->GetSpacingX() || m_SpacingY != other->GetSpacingY() )
  {
    this->SetSpacing( other->GetSpacingX(), other->GetSpacingY() );
  }

  // Copy buffer.
  for( unsigned int x = 0; x < m_SizeX; ++x )
  {
    for( unsigned int y = 0; y < m_SizeY; ++y )
    {
      this->SetPixel( x, y, other->GetPixel( x, y ) );
    }
  }

  // Return success.
  return true;
}

/* This method release the data of the image buffer (free memory) */
void Image::ReleaseData()
{
  // check if image buffer is allocated
   if ( m_ImageBuffer != NULL )
   {
     // free memory of image buffer
     delete [] m_ImageBuffer;
     m_ImageBuffer = NULL;
   }
}
