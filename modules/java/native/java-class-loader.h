/*
 * Copyright (c) 2010-2014 BalaBit IT Ltd, Budapest, Hungary
 * Copyright (c) 2010-2014 Viktor Juhasz <viktor.juhasz@balabit.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As an additional exemption you are allowed to compile & link against the
 * OpenSSL libraries as published by the OpenSSL project. See the file
 * COPYING for details.
 *
 */


#ifndef JAVA_CLASS_LOADER_H_
#define JAVA_CLASS_LOADER_H_

#include <jni.h>
#include <syslog-ng.h>

typedef struct _ClassLoader {
  jclass syslogng_class_loader;
  jobject loader_object;
  jmethodID mi_constructor;
  jmethodID mi_loadclass;
  jmethodID mi_init_current_thread;
} ClassLoader;


ClassLoader *class_loader_new(JNIEnv *java_env);
void class_loader_free(ClassLoader *self, JNIEnv *java_env);
jclass class_loader_load_class(ClassLoader *self, JNIEnv *java_env, const gchar *class_name, const gchar *class_path);
void class_loader_init_current_thread(ClassLoader *self, JNIEnv *env);


#endif /* JAVA_CLASS_LOADER_H_ */
