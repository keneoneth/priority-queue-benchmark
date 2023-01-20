import os
import subprocess
import pandas as pd

TEST_CAND_ARR = ["A","B","C","D"]
TEST_TYPE = ["I","II"]
TEST_ID = ["i","ii","iii","iv","v","vi"]
RESULT_PATH = "results"

res_path = lambda report : os.path.join(RESULT_PATH,report)

def parse_out_to_dict(out,need_s=False,prec=4):
    ret = {}
    for line in out:
        if line.startswith("[TEST]"):
            d = eval(line[len("[TEST]"):])
            ret.update(d)
    if "elapsed_time_us" in ret:
        ret["elapsed_time_ms"] = [round(ret["elapsed_time_us"][0]/1000,prec)]
        if need_s:
            ret["elapsed_time_s"] = [round(ret["elapsed_time_ms"][0]/1000,prec)]
    return pd.DataFrame(ret)

def run_test(tcand,ttype,tid,need_s=False):
    cmd = f"make clean && make run cand={tcand} type={ttype} id={tid}"
    print(f"cmd: {cmd}")
    try:
        out = subprocess.check_output(cmd,shell=True).decode('utf-8').split('\n')
        out = parse_out_to_dict(out,need_s)
    except:
        out = parse_out_to_dict({})
    return out

def test_all():
    func_name = "test_all"
    report_name = f"{func_name}_result.csv"
    out_arr = []
    for tcand in TEST_CAND_ARR:
        for ttype in TEST_TYPE:
            for tid in TEST_ID:
                out = run_test(tcand,ttype,tid,need_s=True)
                out_arr.append(out)
    result = pd.concat(out_arr)
    result.to_csv(res_path(report_name),index=False)
    print(f"test result is written to {res_path(report_name)}")
    print(f"{func_name} done !!!")

def test_I():
    func_name = "test_I"
    report_name = f"{func_name}_result.csv"
    out_arr = []
    for tcand in TEST_CAND_ARR:
        ttype = 'I'
        for tid in TEST_ID:
            out = run_test(tcand,ttype,tid,need_s=True)
            out_arr.append(out)
    result = pd.concat(out_arr)
    result.to_csv(res_path(report_name),index=False)
    print(f"test result is written to {res_path(report_name)}")
    print(f"{func_name} done !!!")

def test_II():
    func_name = "test_II"
    report_name = f"{func_name}_result.csv"
    out_arr = []
    for tcand in TEST_CAND_ARR:
        ttype = 'II'
        for tid in TEST_ID[:-1]:
            out = run_test(tcand,ttype,tid,need_s=True)
            out_arr.append(out)
    result = pd.concat(out_arr)
    result.to_csv(res_path(report_name),index=False)
    print(f"test result is written to {res_path(report_name)}")
    print(f"{func_name} done !!!")

def test_simple_I():
    func_name = "test_simple_I"
    report_name = f"{func_name}_result.csv"
    out_arr = []
    for tcand in TEST_CAND_ARR[:]:
        ttype = 'I'
        for tid in TEST_ID[:TEST_ID.index('iv')+1]:
            out = run_test(tcand,ttype,tid)
            out_arr.append(out)
    result = pd.concat(out_arr)
    result.to_csv(res_path(report_name),index=False)
    print(f"test result is written to {res_path(report_name)}")
    print(f"{func_name} done !!!")

def test_simple_II():
    func_name = "test_simple_II"
    report_name = f"{func_name}_result.csv"
    out_arr = []
    for tcand in TEST_CAND_ARR[:]:
        ttype = 'II'
        for tid in TEST_ID[:TEST_ID.index('iii')+1]:
            out = run_test(tcand,ttype,tid)
            out_arr.append(out)
    result = pd.concat(out_arr)
    result.to_csv(res_path(report_name),index=False)
    print(f"test result is written to {res_path(report_name)}")
    print(f"{func_name} done !!!")

def test_single():
    func_name = "test_single"
    report_name = f"{func_name}_result.csv"
    out_arr = []
    tcand = 'A'
    ttype = 'I'
    tid = 'i'
    out = run_test(tcand,ttype,tid)
    out_arr.append(out)
    result = pd.concat(out_arr)
    result.to_csv(res_path(report_name),index=False)
    print(f"test result is written to {res_path(report_name)}")
    print(f"{func_name} done !!!")

if __name__ == "__main__":
    test_single()