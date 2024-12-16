sapids_list=sapid.strip().replace("'","").replace('"',"").split(",")
email_list=[]
for i in range(len(sapids_list)):
    email_list.append(f"'{sapids_list[i]}@stu.upes.ac.in'")
return"["+",".join(email_list)+"]"