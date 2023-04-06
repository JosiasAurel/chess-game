import os

files = os.listdir()

for file in files:
    result = file.split("_")
    if file == "rename.py":
        continue
    if result[0] == "b":
        path = os.path.join(".", f"{result[1]}_black.png")
    else:
        path = os.path.join(".", f"{result[1]}_white.png")

    os.rename(os.path.join(".", file), path)



