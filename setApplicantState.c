void setApplicantState(char* majorRequirements) {
    int i, assignedIndex = -1;
    float maxPoints = 0.0;

    for (i = 0; i < numOfLines; i++) {
        if (strstr(majorRequirements, list[i].major) != NULL) {
            strcpy(list[i].State, "candidate");

            if (list[i].Points > maxPoints) {
                maxPoints = list[i].Points;
                assignedIndex = i;
            }
        }
    }

    if (assignedIndex != -1) {
        strcpy(list[assignedIndex].State, "Assigned");
    }
}