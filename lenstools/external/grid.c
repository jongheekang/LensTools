#include "grid.h"

//Snap particles on a 3d regularly spaced grid
int grid3d(float *positions,int Npart,double leftX,double leftY,double leftZ,double sizeX,double sizeY,double sizeZ,int nx,int ny,int nz,float *grid){

	int n,i,j,k;

	//Cycle through the particles and for each one compute the position on the grid
	for(n=0;n<Npart;n++){

		//Compute the position on the grid in the fastest way
		i = (int)((positions[3*n] - leftX)/sizeX);
		j = (int)((positions[3*n + 1] - leftY)/sizeY);
		k = (int)((positions[3*n + 2] - leftZ)/sizeZ);

		//If the particle lands on the grid, put it in the correct pixel
		if(i>=0 && i<nx && j>=0 && j<ny && k>=0 && k<nz){

			grid[i*ny*nz + j*nz + k] += 1.0;

		}


	}


	return 0;


}