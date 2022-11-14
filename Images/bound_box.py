from PIL import ImageDraw
from PIL import Image
from kraken import pageseg

def show_boxes(path):
    img = Image.open(path)
    drawing_object = ImageDraw.Draw(img)
    bounding_boxes = pageseg.segment(img.convert('1'))['boxes']
    for box in bounding_boxes:
        drawing_object.rectangle(box, fill = None, outline ='red')
    img.show()
    return img
