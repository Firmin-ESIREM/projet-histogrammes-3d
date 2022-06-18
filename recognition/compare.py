from sys import argv, exit
from collections import Counter

if len(argv) < 2:
    exit(1)

def parse_model(path):
    with open(path, 'r') as f:
        content = f.read()
        content = content.split("\n")
        content.pop(0)
        sums = []
        for el in content:
            if len(el) > 0:
                sums.append(float(el.split(';')[2]))
        return sums

with open(argv[1], 'r') as f:
    ref_list = f.read()

with open(argv[2], 'r') as f:
    to_compare_list = f.read()

models_to_compare_files = to_compare_list.split('\n')
models_to_compare = []
for mod in models_to_compare_files:
    if mod != "":
        models_to_compare.append(parse_model("output_test/" + mod))

ref_models_files = ref_list.split('\n')
ref_models = []
for mod in ref_models_files:
    if mod != "":
        ref_models.append(parse_model("output_training/" + mod))


for h, model_to_compare in enumerate(models_to_compare):
    matching = 0
    matching_sim_index = 0
    similarities = []

    for i, model in enumerate(ref_models):
        try:
            if models_to_compare_files[h].split("_")[-1] in ref_models_files[i]:
                difference_index = 0
                for k, face in enumerate(model_to_compare):
                    difference_index += abs(model[k] - face)
                similarity_index = 1 - difference_index
                similarities.append({"model": ref_models_files[i], "similarity": similarity_index})
        except Exception as e:
            with open("exception.txt", 'a') as f:
                print(f"Exception {str(e)} when comparing {models_to_compare_files[h]} to {ref_models_files[i]}.")
                f.write(f"Exception {str(e)} when comparing {models_to_compare_files[h]} to {ref_models_files[i]}.")
    
    similarities.sort(key=lambda x: x["similarity"], reverse=True)


    matching_classes = []

    for i in range(0, 5):
        file_name = similarities[i]["model"].split('_')
        del file_name[-2:]
        matching_classes.append('_'.join(file_name))

    counted_classes = dict(Counter(matching_classes))
    could_be = []
    could_be_nb = 0

    for key, value in counted_classes.items():
        if value > could_be_nb:
            could_be = [key]
            could_be_nb = value
        elif value == could_be_nb:
            could_be.append(key)
    
    could_be_str = ','.join(could_be)

    with open("result.txt", 'a') as f:
        f.write(f"{models_to_compare_files[h]} -> {could_be_str}\n")

    print(f"[v] Compared {models_to_compare_files[h]}.")
