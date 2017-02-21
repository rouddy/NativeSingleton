package com.rouddy.nativesingleton;

import android.util.Log;

/**
 * Created by yoojaehong on 2016. 8. 11..
 */

public abstract class NativeSingleton {

	static {
		System.loadLibrary("singleton");
	}

	public static NativeSingleton getInstance(Class<? extends NativeSingleton> clazz) {
		NativeSingleton instance = getSingleton(clazz);
		if (instance == null) {
			try {
				instance = clazz.newInstance();
				setSingleton(clazz, instance);
			} catch (InstantiationException e) {
				throw new RuntimeException("cannot create instance", e);
			} catch (IllegalAccessException e) {
				throw new RuntimeException("cannot create instance", e);
			}
		}

		return instance;
	}

	private native static NativeSingleton getSingleton(Class clazz);
	private native static void setSingleton(Class clazz, NativeSingleton object);
}
