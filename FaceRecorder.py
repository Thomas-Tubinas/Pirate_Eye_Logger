import cv2
import tkinter as tk
import threading

scanFace = cv2.CascadeClassifier(
    cv2.data.haarcascades + "haarcascade_frontalface_default.xml"
)

cap = cv2.VideoCapture(0)

root = tk.Tk()
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()
root.destroy()

def detect_bounding_box(vid):
    image = cv2.cvtColor(vid, cv2.COLOR_BGR2GRAY)
    faces = scanFace.detectMultiScale(image, 1.1, 6, minSize=(40, 40))
    for (x, y, w, h) in faces:
        cv2.rectangle(vid, (x, y), (x + w, y + h), (255, 0, 255), 4)
    return len(faces) > 0

video_playing = False

while True:
    ret, frame = cap.read()
    result, image = cap.read()
    frame = cv2.resize(frame, (screen_width, screen_height))
    faces = detect_bounding_box(frame)
    if faces:
        cv2.imwrite("GeeksForGeeks.png", image)

cap.release()
cv2.destroyAllWindows()
