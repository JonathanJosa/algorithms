import pytesseract
from PIL import Image

def binarize(file_name, threshold):
    # greyscale image using convert()
    output_image = Image.open(file_name).convert("L")
    # if it's greater than the threshold, turn it all the way up (255), and
    # if it's lower than the threshold, turn it all the way down (0).
    for x in range(output_image.width):
        for y in range(output_image.height):
            if output_image.getpixel((x,y)) < threshold:
                output_image.putpixel( (x,y), 0 )
            else:
                output_image.putpixel( (x,y), 255 )

    print("Trying with threshold " + str(threshold))
    output_image.show()
    print(pytesseract.image_to_string(output_image))

    return output_image
