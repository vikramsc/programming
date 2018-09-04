#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * A file version.txt has following content with appName, API name, version
 *
 * Mail App, Authentication API, v6
 * Video Call App, Authentication API, v7
 * Mail App, Data Storage API, v10
 * Chat App, Data Storage API, v11
 * Mail App, Search API, v6
 * Chat App, Authentication API, v8
 * Chat App, Presence API, v2
 * Video Call App, Data Storage API, v11
 * Video Call App, Video Compression API, v3
 *
 * Print the name of the app that uses all the latest version of APIs
 */
typedef struct list {
	char api[128];
	int version;
	struct list *next;
}ApiList;

ApiList *api_list = NULL;

typedef struct applist {
	char app[128];
	ApiList *api;
	struct applist *next;
}AppList;

AppList *app_list = NULL;

void insertApp(char *app, char *api, char *version) {
	int ver;
	AppList *tmp = app_list;
	ApiList *apiptr, *tmpapi;
	sscanf(version, " v%d", &ver);

	while (tmp != NULL) {
		if (strcmp(app, tmp->app) == 0) {
			break;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL) {
		AppList *node = (AppList*)malloc(sizeof(AppList));
		strcpy(node->app, app);
		node->next = NULL;
		node->api = (ApiList*) malloc(sizeof(ApiList));
		strcpy(node->api->api, api);
		node->api->next = NULL;
		node->api->version = ver;
		if (app_list == NULL) {
			app_list = node;
		} else {
			node->next = app_list;
			app_list = node;
		}
	} else {
		apiptr =(ApiList*) malloc(sizeof(ApiList));
		strcpy(apiptr->api, api);
		apiptr->next = NULL;
		apiptr->version = ver;
		apiptr->next = tmp->api;
		tmp->api = apiptr;
	}
}

void insertApi(char *api, char *version) {
	int ver;
	ApiList *tmp = api_list;
	sscanf(version, " v%d", &ver);
	while (tmp != NULL) {
		if (strcmp(api, tmp->api) == 0) {
			if (tmp->version < ver) {
				tmp->version = ver;
				break;
			}
		}
		tmp = tmp->next;
	}
	if (tmp == NULL) {
		// new node
		ApiList *node = (ApiList*)malloc(sizeof (ApiList));
		strcpy(node->api, api);
		node->version = ver;
		node->next = NULL;
		if (api_list == NULL) {
			api_list = node;
		} else {
			node->next = api_list;
			api_list = node;
		}
	}
}

int isAllVersionLatest(AppList *node) {
	ApiList *tmpapi = node->api;
	ApiList *ptr; 
	int latest = 1;

	while (tmpapi != NULL) {
		ptr = api_list;
		while (ptr != NULL) {
			if (strcmp(ptr->api, tmpapi->api) == 0) {
				if (ptr->version != tmpapi->version) {
					latest = 0;
					break;
				}
			}
			ptr = ptr->next;
		}
		tmpapi = tmpapi->next;
	}
	return latest;
}

void printLatestVersionApps(char *fileName) {
	char *app, *api, *version;;
	char buf[256];
	int ret; 
	ApiList *tmpapi;
	AppList *tmpapp;

	FILE *fp = fopen(fileName, "r");
	while (fgets(buf, sizeof(buf), fp) != NULL) {
		buf[strlen(buf) - 1] = '\0';
		char *app = strtok(buf, ",");
		api = strtok(NULL, ",");
		version = strtok(NULL, ",");
		insertApi(api, version);
		insertApp(app, api, version);
	}
	close(fp);

	tmpapp = app_list;
	while (tmpapp != NULL) {
		if (isAllVersionLatest(tmpapp)) {
			printf("%s\n", tmpapp->app);
		}
		tmpapp = tmpapp->next;
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		return -1;
	}
	printLatestVersionApps(argv[1]);
	return 0;
}
