import math
from PIL import Image

def show_faces(img, faces):
    if faces == ():
        print("There is no faces here")
    else:
        images = []
        for x,y,w,h in faces:
            images.append(img.crop((x, y, x+w, y+h)))

        totalImages = len(images)
        contact_sheet = Image.new(images[0].mode, (600, 120*math.ceil(totalImages/5)))

        for i in range(totalImages):
            x = (i%5)*120
            y = (i//5)*120
            contact_sheet.paste(images[i].resize((120, 120)), (x, y))

        contact_sheet.show()
        return contact_sheet
