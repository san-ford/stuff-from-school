#------------------------------------------------------------------------------
# Vector.py
#------------------------------------------------------------------------------
"""
This module provides functions to perform standard vector operations.  Vectors
are represented as tuples of numbers (floats or ints).  Functions that take two 
vector arguments will raise a ValueError() exception if the two vectors are of
different dimensions.  
"""
#------------------------------------------------------------------------------
# import library modules
#------------------------------------------------------------------------------
import math
import random

#------------------------------------------------------------------------------
# function definitions
#------------------------------------------------------------------------------

# add() -----------------------------------------------------------------------
def add(u, v):
    """
    Return the vector sum u+v.
    """
    # makes sure the vectors have the same dimension
    if not (len(u) == len(v)):
        raise ValueError('incompatible vectors: '+str(u)+', '+str(v))
    # end if

    L = []
    for i in range(len(u)):
        L.append(u[i]+v[i])
    # end for
    w = tuple(L)
    return w
# end add() -------------------------------------------------------------------


# negate() --------------------------------------------------------------------
def negate(u):
    """
    Return the negative of the vector u.
    """
    L = []
    for i in range(len(u)):
        L.append(-u[i])
    # end for
    w = tuple(L)
    return w
# end negate() ----------------------------------------------------------------   


# sub() -----------------------------------------------------------------------
def sub(u, v):
    """
    Return the vector difference u-v.
    """
    # makes sure the vectors have the same dimension
    if not (len(u) == len(v)):
        raise ValueError('incompatible vectors: '+str(u)+', '+str(v))
    # end if

    L = []
    for i in range(len(u)):
        L.append(u[i]-v[i])
    # end for
    w = tuple(L)
    return w
# end sub() -------------------------------------------------------------------


# scalarMult() ----------------------------------------------------------------
def scalarMult(c, u):
    """
    Return the scalar product cu of the number c by the vector u.
    """
    L = []
    for i in range(len(u)):
        L.append(c*u[i])
    # end for
    w = tuple(L)
    return w
# end scalarMult() ------------------------------------------------------------


# hadamard() ------------------------------------------------------------------
def hadamard(u, v):
    """
    Return the Hadamard product of u with v.
    """
    # makes sure the vectors have the same dimension
    if not (len(u) == len(v)):
        raise ValueError('incompatible vectors: '+str(u)+', '+str(v))
    # end if

    L = []
    for i in range(len(u)):
        L.append(u[i]*v[i])
    # end for
    w = tuple(L)
    return w
# end hadamard() --------------------------------------------------------------


# dot() -----------------------------------------------------------------------
def dot(u, v):
    """
    Return the dot product of u with v.
    """
    # makes sure the vectors have the same dimension
    if not (len(u) == len(v)):
        raise ValueError('incompatible vectors: '+str(u)+', '+str(v))
    # end if

    L = []
    for i in range(len(u)):
        L.append(u[i]*v[i])
    # end for
    w = sum(L)
    return w
# end dot() -------------------------------------------------------------------


# length() --------------------------------------------------------------------
def length(u):
    """
    Return the (geometric) length of the vector u.
    """
    L = []
    for i in range(len(u)):
        L.append(u[i]**2)
    # end for
    w = math.sqrt(sum(L))
    return w
# end length() ----------------------------------------------------------------


# dim() -----------------------------------------------------------------------
def dim(u):
    """
    Return the dimension of the vector u.
    """
    w = len(u)
    return w
# end dim() -------------------------------------------------------------------


# unit() ----------------------------------------------------------------------
def unit(v):
    """
    Return a unit (geometric length 1) vector in the direction of v.
    """
    x = length(v)
    L = []
    for i in range(len(v)):
        L.append(v[i]/x)
    # end for
    w = tuple(L)
    return w
# end unit() ------------------------------------------------------------------


# angle() ---------------------------------------------------------------------
def angle(u, v):
    """
    Return the angle (in radians) between vectors u and v.
    """
    # makes sure the vectors have the same dimension
    if not (len(u) == len(v)):
        raise ValueError('incompatible vectors: '+str(u)+', '+str(v))
    # end if

    # x is the dot product of the unit vectors of u and v
    x = dot(unit(u), unit(v))
    w = math.acos(x)
    return w
# end angle() -----------------------------------------------------------------


# randVector() ----------------------------------------------------------------
def randVector(n, a, b):
    """
    Return a vector of dimension n whose components are random floats in
    the range [a, b).
    """
    L = []
    for i in range(n):
        L.append(random.uniform(a, b))
    # end for
    w = tuple(L)
    return w
# end randomVector() ----------------------------------------------------------

