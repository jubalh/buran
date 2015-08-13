# buran

A simple SSH shortcut menu for Linux.

Someone created [Shuttle](http://fitztrev.github.io/shuttle/), then ~~the russians~~ I came along and created buran.

It has *less* features than Shuttle:

- just one setting can be made in the config file: which terminal should be used to run ssh
- It get's all information regarding your connection from your ssh config doesn't use any other files

## Customization

buran will parse your `~/.ssh/config` file for hosts.

### Nested menus for `~/.ssh/config` hosts

#### Create a menu item at "work" > "ESA" > "soyuz"

```
Host work/ESA/soyuz
	HostName merbold@soy.srv.esa.int
```

## Credit

Thanks to [Trevor Fitzgerald](http://trevorfitzgerald.com/) for creating [Shuttle](http://fitztrev.github.io/shuttle/).
I used it when I was on OS X. And I liked it. When I was looking for a pet project to get more experience with Qt, I started buran.
