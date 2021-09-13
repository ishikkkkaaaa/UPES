import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
from sklearn.datasets import make_regression

#%%
# generate  dataset
X,y = make_regression(n_samples=100, n_features=5,noise=50)

#%%
#plot the graph
plt.scatter(X[:,2],y)

#%%
#Train test Split
X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.3) #30%test and 70% train dataset.

#%%
#implement Polynomial Regression
poly = PolynomialFeatures(degree = 3)  # degree of polynomial=3
X_poly = poly.fit_transform(X_train)
  
poly.fit(X_poly, y_train)
model = LinearRegression()
model.fit(X_poly, y_train)
X_poly_test=poly.fit_transform(X_test)

#%%
#predicting through polynomial Regression(Linear Regression Model)
y_pred_=model.predict(X_poly_test)

#%%
#print rmse
from sklearn.metrics import mean_squared_error
rms = mean_squared_error(y_test, y_pred_)
print("RMS Score:")
print(rms)
#%%

#print log error

from sklearn.metrics import mean_squared_log_error
logerr=mean_squared_log_error(abs(y_test), abs(y_pred_))
print("RMS Log error")
print(logerr)


#%%
#print R^2 Coffecient of determinatiom

from sklearn.metrics import r2_score
r2_sc=r2_score(y_test,y_pred_)
print("R^2")
print(r2_sc)
#%%
#implement through ridgeCV
from sklearn.linear_model import RidgeCV
model01=RidgeCV(alphas=[1e-3,1e-2,1e-1,1])
model01.fit(X_poly,y_train)

#%%
#prediction
y_pred_rid=model01.predict(X_poly_test)

#%%
#calculate rmse ,log error and R^2 score 
rms_rid=mean_squared_error(y_test, y_pred_rid)
print("RMSE Error: ",rms_rid)
log_rid=mean_squared_log_error(abs(y_test), abs(y_pred_rid))
print("Log Error: ",log_rid)
r2_sc_ridge=r2_score(y_test,y_pred_rid)
print("R^2 Score: ",r2_sc_ridge)

#%%
#implement cross validation model
from sklearn.model_selection import KFold,cross_val_score
folds = KFold(n_splits = 5, shuffle = True, random_state = 100)
scores = cross_val_score(model, X_train, y_train, scoring='neg_mean_absolute_error', cv=folds)
print(np.average(scores) )     


 #%%
 
 
 





