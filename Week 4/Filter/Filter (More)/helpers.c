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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    double Gx_totalRed, Gx_totalGreen, Gx_totalBlue, Gy_totalRed, Gy_totalGreen, Gy_totalBlue;
    RGBTRIPLE(*temp)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    //create a copy of the image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Gx_totalRed = 0;
            Gx_totalGreen = 0;
            Gx_totalBlue = 0;
            Gy_totalRed = 0;
            Gy_totalGreen = 0;
            Gy_totalBlue = 0;

            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    int currentX = i + x - 1;
                    int currentY = j + y - 1;

                    //if the x and y coordinate are out of bound, then we skip it
                    if (currentX >= 0 && currentX < height && currentY >= 0 && currentY < width)
                    {
                        Gx_totalRed += Gx[x][y] * temp[currentX][currentY].rgbtRed;
                        Gx_totalGreen += Gx[x][y] * temp[currentX][currentY].rgbtGreen;
                        Gx_totalBlue += Gx[x][y] * temp[currentX][currentY].rgbtBlue;

                        Gy_totalRed += Gy[x][y] * temp[currentX][currentY].rgbtRed;
                        Gy_totalGreen += Gy[x][y] * temp[currentX][currentY].rgbtGreen;
                        Gy_totalBlue += Gy[x][y] * temp[currentX][currentY].rgbtBlue;
                    }
                }
            }

            //apply the formula and check if it is more than 255 or not
            image[i][j].rgbtRed = sqrt(Gx_totalRed * Gx_totalRed + Gy_totalRed * Gy_totalRed) > 255 ? 255 : round(sqrt(
                                      Gx_totalRed * Gx_totalRed + Gy_totalRed * Gy_totalRed));
            image[i][j].rgbtGreen = sqrt(Gx_totalGreen * Gx_totalGreen + Gy_totalGreen * Gy_totalGreen) > 255 ? 255 : round(sqrt(
                                        Gx_totalGreen * Gx_totalGreen + Gy_totalGreen * Gy_totalGreen));
            image[i][j].rgbtBlue = sqrt(Gx_totalBlue * Gx_totalBlue + Gy_totalBlue * Gy_totalBlue) > 255 ? 255 : round(sqrt(
                                       Gx_totalBlue * Gx_totalBlue + Gy_totalBlue * Gy_totalBlue));
        }
    }

    return;
}
