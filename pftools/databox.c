/*BHEADER**********************************************************************

  Copyright (c) 1995-2009, Lawrence Livermore National Security,
  LLC. Produced at the Lawrence Livermore National Laboratory. Written
  by the Parflow Team (see the CONTRIBUTORS file)
  <parflow@lists.llnl.gov> CODE-OCEC-08-103. All rights reserved.

  This file is part of Parflow. For details, see
  http://www.llnl.gov/casc/parflow

  Please read the COPYRIGHT file or Our Notice and the LICENSE file
  for the GNU Lesser General Public License.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License (as published
  by the Free Software Foundation) version 2.1 dated February 1999.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms
  and conditions of the GNU General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA
**********************************************************************EHEADER*/
/******************************************************************************
 * NewDatabox and FreeDatabox
 *
 * see info_header.h for complete information
 *
 *****************************************************************************/

#include "databox.h"
#include <stdlib.h>

/*-----------------------------------------------------------------------
 * create new Databox structure
 *-----------------------------------------------------------------------*/

Databox         *NewDatabox(nx, ny, nz, x, y, z, dx, dy, dz)
int             nx, ny, nz;
double          x,  y,  z;
double          dx, dy, dz;
{
   Databox         *new;

   if ((new = calloc(1, sizeof (Databox))) == NULL)
      return((Databox *)NULL);

   if ((DataboxCoeffs(new) = calloc((nx * ny * nz), sizeof (double))) == NULL){
      free(new);
      return((Databox *)NULL);
   }

   DataboxNx(new) = nx;
   DataboxNy(new) = ny;
   DataboxNz(new) = nz;

   DataboxX(new)  = x;
   DataboxY(new)  = y;
   DataboxZ(new)  = z;

   DataboxDx(new) = dx;
   DataboxDy(new) = dy;
   DataboxDz(new) = dz;

   return new;
}


/*-----------------------------------------------------------------------
 * print Databox grid info
 *-----------------------------------------------------------------------*/

void            GetDataboxGrid(interp, databox)
Tcl_Interp     *interp;
Databox        *databox;
{
   Tcl_Obj     *result = Tcl_GetObjResult(interp);
   Tcl_Obj     *double_obj;
   Tcl_Obj     *int_obj;
   Tcl_Obj     *list_obj;

   list_obj = Tcl_NewListObj(0, NULL);

   int_obj = Tcl_NewIntObj(DataboxNx(databox));
   Tcl_ListObjAppendElement(interp, list_obj, int_obj);

   int_obj = Tcl_NewIntObj(DataboxNy(databox));
   Tcl_ListObjAppendElement(interp, list_obj, int_obj);

   int_obj = Tcl_NewIntObj(DataboxNz(databox));
   Tcl_ListObjAppendElement(interp, list_obj, int_obj);

   Tcl_ListObjAppendElement(interp, result, list_obj);
   list_obj = Tcl_NewListObj(0, NULL);

   double_obj = Tcl_NewDoubleObj(DataboxX(databox));
   Tcl_ListObjAppendElement(interp, list_obj, double_obj);

   double_obj = Tcl_NewDoubleObj(DataboxY(databox));
   Tcl_ListObjAppendElement(interp, list_obj, double_obj);

   double_obj = Tcl_NewDoubleObj(DataboxZ(databox));
   Tcl_ListObjAppendElement(interp, list_obj, double_obj);

   Tcl_ListObjAppendElement(interp, result, list_obj);
   list_obj = Tcl_NewListObj(0, NULL);

   double_obj = Tcl_NewDoubleObj(DataboxDx(databox));
   Tcl_ListObjAppendElement(interp, list_obj, double_obj);

   double_obj = Tcl_NewDoubleObj(DataboxDy(databox));
   Tcl_ListObjAppendElement(interp, list_obj, double_obj);

   double_obj = Tcl_NewDoubleObj(DataboxDz(databox));
   Tcl_ListObjAppendElement(interp, list_obj, double_obj);

   Tcl_ListObjAppendElement(interp, result, list_obj);

}

/*-----------------------------------------------------------------------
 * free Databox structure
 *-----------------------------------------------------------------------*/

void         FreeDatabox(databox)
Databox      *databox;
{
   free(DataboxCoeffs(databox));

   free(databox);
}


