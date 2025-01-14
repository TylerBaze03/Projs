
from atproto import Client, client_utils
def main():


    client = Client()
    profile = client.login('wasdwaasdw.bsky.social', 'xxxx')
    print('Welcome, ', profile.display_name)


    post = client.send_post("Hihi")
    post.uri
    post.cid
    
if __name__ == '__main__':
    main()

