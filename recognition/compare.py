from sys import argv, exit

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

    for i, model in enumerate(ref_models):
        try:
            if models_to_compare_files[h].split("_")[-1] in ref_models_files[i]:
                difference_index = 0
                for k, face in enumerate(model_to_compare):
                    difference_index += abs(model[k] - face)
                similarity_index = 1 - difference_index
                if matching_sim_index < similarity_index:
                    matching_sim_index = similarity_index
                    matching = i
        except Exception as e:
            with open("exception.txt", 'a') as f:
                print(f"Exception {str(e)} when comparing {models_to_compare_files[h]} to {ref_models_files[i]}.")
                f.write(f"Exception {str(e)} when comparing {models_to_compare_files[h]} to {ref_models_files[i]}.")

    with open("result.txt", 'a') as f:
        f.write(f"{models_to_compare_files[h]} -> {ref_models_files[matching]} ({str(matching_sim_index)})\n")

    print(f"[v] Compared {models_to_compare_files[h]}.")
