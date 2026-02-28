/*Author: Rhys B
This program looks at each pixel in an image by raster order order (left to right, row by row) 
and groups pixels into segments based on color similarity. 
*/


//main program 


//load in image and call it 'input'
//create blank image called 'output' with same dimensions as 'input'
// create empty master container 

// ==== Image For Loop ====

//close enough formula = abs(seed.red - p.red) + abs(seed.green - p.green) + abs(seed.blue - p.blue) < 100

//parse image row by row, left to right
//for loop image rows {
//  for loop image cols{
//  if (output image pixel at row/col == black ) add corresponding input image pixel to new group container 
//      and call it 'seed' for said container. Store seed color value

//      recursively search all neighbouring pixels from input image (left, right, above, and below)
//      base case = all possible neighboring pixels != close enough to seed
//      if (neighbouring pixel color == close enough color to seed) add pixel from input image to group container and 
//      drop a breadcrumb by making it some non-black color in the output image.
//      otherwise, leave it alone stay black 

//      use average color method on the container 
//      increment total segment counter by one for each container made
//      print current container onto the output image
//      merge this container to a master container 
//         
//  repeats process to next segment until all pixels have been parsed and assigned to a segment.
//  }
//}

//      while loop master container{
//          add one to the count for each pixel(node) in container
//      }
//      returns total number of pixels in master container

//      Average color method on master container to print to terminal.
//      Parse pixel into three channels to output it to terminal.


//Save gif file to some name and save.


