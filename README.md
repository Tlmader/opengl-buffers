# csci4631-hw5
Renders an arbitrary number of lines (for meshes) or polygons (for rendering solids) using OpenGL.

#### Class MeshBuffer includes:
* A function to add a “line” or “edge” to the mesh, such that the vertices are not duplicated.
* A function to modify the position of a particular vertex, without disrupting the topology of the mesh.
* A function to retrieve the entire mesh in a data format that is consistent with it being passed directly into OpenGL.

#### Class TriangleBuffer includes:
* A function to add a “triangle” to the solid, such that the vertices are not duplicated.
* A function to modify the position of a particular vertex, without disrupting the topology of the solid.
* A function to calculate the normal to that triangle (and save it).
* A function to recalculate of normals for each triangle involved in vertex modification.
* A function to retrieve the entire solid in a data format that is consistent with it being passed directly into OpenGL.

Uses Angel’s vec.h tools to represent vertices and normals in 3D homogenous coordinates.
