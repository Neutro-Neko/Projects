class Note:
    __count = 0
    def __init__(self, content = "", title = ""):
        self.__id = Note.__count
        Note.__count += 1
        self._content = content
        self._title = title
    def get_note(self):
        # noinspection PyRedundantParentheses
        return (self._content, self._title)   # parentheses for clarity
    def get_vars(self):
        dict = self.__dict__
        dict.update({"count": Note.__count})
        return dict
note_0 = Note("tit","le")
note_1 = Note("no","te")
print(note_0.get_vars())
print(note_0.get_note())
print(note_1.get_vars())
print(note_1.get_note())

#different program
from time import sleep
import threading
j = 0
def thread_func(name, sleep_time):
    global j
    for i in range(100):
        print(f"{name}: {j}")
        j += 1
        sleep(sleep_time)
threads = []
for i in range(100):
    threads.append(threading.Thread(target=thread_func, args=(f"thread-{i}",1)))
    threads[i].start()

