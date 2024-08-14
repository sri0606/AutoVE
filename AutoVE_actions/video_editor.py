from text_to_action import ActionDispatcher
from dotenv import load_dotenv
load_dotenv()

class AutoVE:
    dispatcher = ActionDispatcher(action_embedding_filename="autove.h5",actions_filepath="autove.py",
                                use_llm_extract_parameters=True,verbose_output=True)
    def __init__(self):
        pass

    def load_video(self):
        pass
    def undo_action(self):
        pass
    def redo_action(self):
        pass
    def save_video(self):
        pass
    def edit_video(self):
        pass
