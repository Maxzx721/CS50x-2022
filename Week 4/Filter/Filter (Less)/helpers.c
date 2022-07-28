#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // sum up all the color and divide it by 3
            temp = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = temp;
            image[i][j].rgbtGreen = temp;
            image[i][j].rgbtBlue = temp;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[2];

    //turn every pixel into sepia with the given formula
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[0] = image[i][j].rgbtRed;
            temp[1] = image[i][j].rgbtGreen;
            image[i][j].rgbtRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue > 255 ? 255 : round(
                                      .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            image[i][j].rgbtGreen = .349 * temp[0] + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue > 255 ? 255 : round(
                                        .349 * temp[0] + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            image[i][j].rgbtBlue = .272 * temp[0] + .534 * temp[1] + .131 * image[i][j].rgbtBlue > 255 ? 255 : round(
                                       .272 * temp[0] + .534 * temp[1] + .131 * image[i][j].rgbtBlue);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //create an array of copy
    RGBTRIPLE(*temp)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    //copy every pixel form image to temp
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    //reflect the image horizontally
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][width - 1 - j] = temp[i][j];
        }
    }
    free(temp);

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //declare variables
    double counter, totalRed, totalGreen, totalBlue;
    RGBTRIPLE(*temp)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    //create a copy of the image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    //blur the pixel with the given formula
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            counter = 0.0;
            totalRed = 0;
            totalGreen = 0;
            totalBlue = 0;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    //if the x and y coordinate are out of bound, then we skip it
                    if (currentX < 0 || currentX >= height || currentY < 0 || currentY >=  width)
                    {
                        continue;
                    }
                    totalRed += temp[currentX][currentY].rgbtRed;
                    totalGreen += temp[currentX][currentY].rgbtGreen;
                    totalBlue += temp[currentX][currentY].rgbtBlue;
                    counter++;
                }
            }
            image[i][j].rgbtRed = round(totalRed / counter);
            image[i][j].rgbtGreen = round(totalGreen / counter);
            image[i][j].rgbtBlue = round(totalBlue / counter);
        }
    }
    free(temp);

    return;
}
