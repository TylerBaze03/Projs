# Tyler Bazemore
# Cop2500 0v64
# Lab 5 Challenge 3
# Oct 10, 2022
community_events = ["Soccer schedule", "Swim club", "Book club", "Career expo", "Writing lab and tutoring"]
events = ["UCF Family weekend","UCF Tailgate sign up","Tutoring help COP 2500","Anime club meeting","Internship information"]
list_events = ["Engineering Club Meeting", "Basketball Tournament", "Math Tutoring", "Open Mic Night Tomorrow", "Free Shirts Giveaway"]

master_list_1 = list()

master_list_1.extend(events)
master_list_1.extend(list_events)
master_list_1.extend(community_events)

print(list(master_list_1))


master_list_2 = zip(community_events, events, list_events)

print(list(master_list_2))


master_list_3 = list()

master_list_3.extend(master_list_1)
master_list_3.sort()

print(list(master_list_1))

