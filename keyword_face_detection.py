from PIL import Image
import pytesseract
import cv2 as cv
import numpy as np

def search_zip(path, keyword, path_dict):
    face_cascade = cv.CascadeClassifier(path_dict)
    images = []
    data = []
    with zipfile.ZipFile(path, 'r') as dataZip:
        for img in dataZip.infolist():
            image_file = Image.open(dataZip.open(img))
            images.append(image_file)
            data.append(pytesseract.image_to_string(image_file))
            print("File readed: ", img)
        print("Complete file reader")

    print("Searching data with keyword", data_search)
    result = []
    for img, text in zip(images, data):
        if keyword in text:
            print("results found")
            result.append((
                face_cascade.detectMultiScale(cv.cvtColor(np.array(img), cv.COLOR_RGB2BGR), 1.5),
                img
            )
    return result
