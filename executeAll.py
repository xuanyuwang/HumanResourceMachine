import os
for root, dirs, files in os.walk("."):
    for file in files:
        if file.endswith(".cpp"):
            filename = os.path.join(root, file)
            output = filename.rstrip(".cpp") + ".out"
            os.system("g++ -w " + filename + " -o " + output + " && " + output)
